# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 18:07:28 by daniema3          #+#    #+#              #
#    Updated: 2025/09/13 17:31:15 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = cub3d

SRC_DIR = ./src
OBJ_DIR = ./objs

LOG_DIR = ./logs
TEST_DIR = ./test

CC = cc

INCLUDE_DIRS =  -I$(SRC_DIR) \
                -I$(SRC_DIR)/parser \
                -I$(SRC_DIR)/util/mem \
                -I$(SRC_DIR)/util/str

CFLAGS =    -Wall -Werror -Wextra \
            -g3 \
            -fdiagnostics-color=always \
            -Wl,--wrap=malloc \
            -Wl,--wrap=free \
            $(INCLUDE_DIRS)

# > ~ Main project files

SRCS =  cub3d.c \
        cb_getter.c \
        cb_exit.c

# > ~ Utils - Memory

SRCS += util/mem/cb_arrfree.c \
        util/mem/cb_malloc.c

# > ~ Utils - Strings

SRCS += util/str/cb_split.c \
        util/str/cb_strendswith.c \
        util/str/cb_strlen.c

# > ~ Auto free & double free prevention (I'M NOT SURE IF WE CAN DO THIS)

SRCS += util/mem/tmp/free_wrapper.c \
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
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline
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
