# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 18:07:28 by daniema3          #+#    #+#              #
#    Updated: 2026/03/01 17:20:32 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = cub3d

SRC_DIR = ./src
OBJ_DIR = ./objs
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LOG_DIR = ./logs

CC = cc

INCLUDE_DIRS =  -I$(SRC_DIR) \
                -I$(SRC_DIR)/parser \
                -I$(SRC_DIR)/render \
                -I$(SRC_DIR)/events \
                -I$(SRC_DIR)/validator \
                -I$(SRC_DIR)/util/char \
                -I$(SRC_DIR)/util/mem \
                -I$(SRC_DIR)/util/str \
                -I$(MLX_DIR) \
                -I$(CST_DIR)/src

CFLAGS =    -Wall -Werror -Wextra \
            -g3 \
            -fdiagnostics-color=always \
            -std=gnu11 \
            $(INCLUDE_DIRS)

# CFLAGS para tests (con CST memcheck)
TEST_CFLAGS = $(CFLAGS) -include $(CST_DIR)/src/cst.h

# > ~ Main project files

SRCS =  cub3d.c \
        cb_getter.c \
        cb_exit.c

# > ~ Render

SRCS += render/render.c \
        render/draw.c \
        render/raycaster.c \
        render/draw_pixel.c

# > ~ Events

SRCS += events/close_window.c \
        events/key_handlers.c \
        events/player_movement.c

# > ~ Parser

SRCS += parser/assets_parser.c \
        parser/color_parser.c \
        parser/is_map_line.c \
        parser/map_reader.c \
        parser/player_parser.c \
        parser/parser.c \
        parser/validate_structure.c

# > ~ Utils - Char

SRCS += util/char/cb_isdigit.c

# > ~ Utils - Memory

SRCS += util/mem/cb_arrfree.c \
        util/mem/cb_malloc.c

# > ~ Utils - Strings

SRCS += util/str/cb_split.c \
        util/str/cb_strdup.c \
        util/str/cb_strendswith.c \
        util/str/cb_strhasch.c \
        util/str/cb_strjoin.c \
        util/str/cb_strlen.c \
        util/str/cb_strstartswith.c

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

# > ~ Compilation function
# Usage: $(call compile_file,source,object,flags,label)
define compile_file
	@mkdir -p $(dir $(2))
	@printf "\r⏳ $(YLW)Compiling $(4) $(BYLW)$(notdir $(1))$(GRAY)...$(RES)"
	@ERR=$$( ($(CC) $(3) -c $(1) -o $(2)) 2>&1 ); \
	if [ $$? -ne 0 ]; then \
		printf "\r\n❌ $(RED)Failed to compile $(4) $(BRED)$(notdir $(2))$(GRAY):$(RES)\n"; \
		echo "$$ERR"; \
		exit 1; \
	else \
		printf "\r✅ $(GREEN)Compiled $(4) $(BGREEN)$(notdir $(1))$(RES)\n"; \
	fi
endef

# > ~ Standard compilation (no CST)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(call compile_file,$<,$@,$(CFLAGS),)

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

re: fclean $(NAME)

NORM_ERRFILE = $(LOG_DIR)/norm_errors.txt

# > ~ Norminette check

norm:
	@mkdir -p $(LOG_DIR)
	@rm -rf $(NORM_ERRFILE)
	@printf "\r⏳ $(YLW)Executing norminette on $(WNAME)$(GRAY)...$(RES)"
	@norminette $(SRC_DIR) | grep "Error" > $(NORM_ERRFILE) || true
	@if [ -s $(NORM_ERRFILE) ]; then \
		printf "\r❌ $(RED)Norm errors found on $(ERRNAME)$(GRAY):$(RES)\n"; \
		sed 's/^Error:/  - /' $(NORM_ERRFILE); \
		exit 1; \
	else \
		printf "\r✅ $(GREEN)No norm errors found on $(OKNAME)!$(RES)\n"; \
		rm -rf $(NORM_ERRFILE); \
	fi

# > ~ Submodules

buildsubmodules:
	@make -C $(MLX_DIR) CFLAGS+="-std=gnu11 -O3 -I$(CURDIR)/minilibx-linux"
	@make -C $(CST_DIR)

submodules:
	@git submodule update --init --recursive
	@make buildsubmodules

cleansubmodules:
	@git submodule deinit --force --all

update:
	@git pull
	@git submodule update --remote --recursive
	@make buildsubmodules
	@make re

# > ~ Test

TEST_DIR = ./test
CST_DIR = ./cst
CST_LIB = $(CST_DIR)/libcst.a
TEST_NAME = CST

TEST_SRCS = $(shell find $(TEST_DIR) -name '*.c' 2>/dev/null)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(OBJ_DIR)/test/%.o)

TEST_BUILD_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/test_build/%.o)
OBJS_NO_MAIN = $(filter-out $(OBJ_DIR)/test_build/cub3d.o, $(TEST_BUILD_OBJS))

$(OBJ_DIR)/test_build/%.o: $(SRC_DIR)/%.c
	$(call compile_file,$<,$@,$(TEST_CFLAGS),for test)

$(OBJ_DIR)/test/%.o: $(TEST_DIR)/%.c
	$(call compile_file,$<,$@,$(TEST_CFLAGS),test)

test: $(OBJS_NO_MAIN) $(TEST_OBJS)
	@make -C $(CST_DIR)
	@$(CC) $(TEST_CFLAGS) $(OBJS_NO_MAIN) $(TEST_OBJS) $(CST_LIB) \
		-o $(TEST_NAME) $(MLX_FLAGS)
	@./$(TEST_NAME)

.PHONY: all clean fclean cleanall re norm buildsubmodules submodules cleansubmodules update test
