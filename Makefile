# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 18:07:28 by daniema3          #+#    #+#              #
#    Updated: 2026/02/09 01:51:21 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = cub3d

SRC_DIR = ./src
OBJ_DIR = ./objs
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LOG_DIR = ./logs
TEST_DIR = ./test

CC = cc

INCLUDE_DIRS =	-I$(SRC_DIR) \
				-I$(SRC_DIR)/parser \
				-I$(SRC_DIR)/render \
				-I$(SRC_DIR)/events \
				-I$(SRC_DIR)/validator \
				-I$(SRC_DIR)/util/char \
				-I$(SRC_DIR)/util/mem \
				-I$(SRC_DIR)/util/str \
				-I$(MLX_DIR)

CFLAGS =	-Wall -Werror -Wextra \
			-g3 \
			-fdiagnostics-color=always \
			-Wl,--wrap=malloc \
			-Wl,--wrap=free \
			-std=gnu11 \
			$(INCLUDE_DIRS)

# > ~ Main project files

SRCS =	cub3d.c \
		cb_getter.c \
		cb_exit.c

# > ~ Render

SRCS +=	render/render.c \
		render/draw.c \
		render/raycaster.c \
		render/draw_pixel.c

# > ~ Events

SRCS +=	events/close_window.c \
		events/key_handlers.c \
		events/player_movement.c

# > ~ Parser

SRCS +=	parser/assets_parser.c \
		parser/color_parser.c \
		parser/is_map_line.c \
		parser/map_reader.c \
		parser/parser.c \
		parser/player_parser.c

# > ~ Validator

SRCS +=	validator/validator.c

# > ~ Utils - Char

SRCS += util/char/cb_isdigit.c

# > ~ Utils - Memory

SRCS +=	util/mem/cb_arrfree.c \
		util/mem/cb_malloc.c

# > ~ Utils - Strings

SRCS += util/str/cb_split.c \
		util/str/cb_strdup.c \
		util/str/cb_strendswith.c \
		util/str/cb_strhasch.c \
		util/str/cb_strjoin.c \
		util/str/cb_strlen.c \
		util/str/cb_strstartswith.c

# > ~ Auto free & double free prevention (I'M NOT SURE IF WE CAN DO THIS)

SRCS +=	util/mem/tmp/free_wrapper.c \
		util/mem/tmp/get_alloc_list.c \
		util/mem/tmp/malloc_wrapper.c

# > ~ .c to .o conversion

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# > ~ Colors!

RED = \033[0;31m
BRED = \033[1;31m
GREEN = \033[0;32m
BGREEN = \033[1;32m
YLW = \033[0;33m
BYLW = \033[1;33m
BLUE = \033[0;36m
BBLUE = \033[1;36m
GRAY = \033[0;30m
RES = \033[0m                                                                   

WNAME = $(BYLW)$(NAME)$(YLW)
OKNAME = $(BLUE)$(NAME)$(GREEN)
ERRNAME = $(BRED)$(NAME)$(RED)

# > ~ Compile

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "\r⏳ $(YLW)Compiling $(BYLW)$(notdir $<)$(GRAY)...$(RES)"
	@{\
		ERR=$$( ($(CC) $(CFLAGS) -c $< -o $@) 2>&1 );\
		if [ $$? -ne 0 ]; then\
			printf "\r\n❌ $(RED)Failed to compile $(BRED)$(notdir $@)$(GRAY):$(RES)\n";\
			echo "$$ERR";\
			exit 1;\
		else\
			printf "\r✅ $(GREEN)Compiled $(BGREEN)$(notdir $<)$(RES)\n";\
		fi;\
	}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) -lreadline
	@printf "\r✅ $(OKNAME) successfully compiled!$(RES)\n"

# > ~ Cleaning

clean:
	@printf "\r⏳ $(YLW)Removing $(WNAME) objs$(GRAY)...$(RES)"
	@rm -rf $(OBJ_DIR)
	@printf "\r✅ $(GREEN)Removed $(OKNAME) objs$(GRAY).$(RES)\n"
	@printf "\r⏳ $(YLW)Removing $(WNAME) coverage files$(GRAY)...$(RES)"
	@rm -rf $(COV_DIR)
	@rm -rf *.gcda *.gcno
	@printf "\r✅ $(GREEN)Removed $(OKNAME) coverage files$(GRAY).$(RES)\n"
	@printf "\r⏳ $(YLW)Removing $(WNAME) logs$(GRAY)...$(RES)"
	@rm -rf $(LOG_DIR)
	@printf "\r✅ $(GREEN)Removed $(OKNAME) logs$(GRAY).$(RES)\n"

fclean: clean
	@printf "\r⏳ $(YLW)Removing $(WNAME) executables$(GRAY)...$(RES)"
	@rm -rf $(NAME)
	@rm -rf $(TEST_NAME)
	@printf "\r✅ $(GREEN)Removed $(OKNAME) executables$(GRAY).$(RES)\n"

cleanall: fclean cleansubmodules

# > ~ Clean & compile

re: fclean $(NAME)

NORM_ERRFILE = $(LOG_DIR)/norm_errors.txt

# > ~ Norminette check

norm:
	@mkdir -p $(LOG_DIR)
	@rm -rf $(NORM_ERRFILE)
	@printf "\r⏳ $(YLW)Executing norminette on $(WNAME)$(GRAY)...$(RES)"
	@norminette $(SRC_DIR) | grep "Error" > $(NORM_ERRFILE) || true
	@if [ -s $(NORM_ERRFILE) ]; then \
		printf "\r❌ $(RED)Norm errors found on $(ERRNAME)$(GRAY):$(RES)\n";\
		sed 's/^Error:/  - /' $(NORM_ERRFILE); \
		exit 1; \
	else \
		printf "\r✅ $(GREEN)No norm errors found on $(OKNAME)!$(RES)\n"; \
		rm -rf $(NORM_ERRFILE); \
	fi

# > ~ Submodules

submodules:
	@git submodule update --init --recursive
	@make -C $(MLX_DIR) CFLAGS+="-std=gnu11 -O3 -I$(CURDIR)/minilibx-linux"

cleansubmodules:
	@git submodule deinit --force --all
