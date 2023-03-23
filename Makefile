# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fra <fra@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/15 00:53:44 by fra           #+#    #+#                  #
#    Updated: 2023/03/09 18:14:49 by fra           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

NAME := fdf
SRC_DIR := sources
OBJ_DIR := objects
MLX42_DIR := MLX42
LIBFT_DIR := libft
MLX42 := $(MLX42_DIR)/build/libmlx42.a
LIBFT := $(LIBFT_DIR)/libft.a
HEADERS := $(shell find include -type f -name '*.h')
SOURCES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.c=.o))

CC  := gcc
IFLAGS := -Iinclude -I$(MLX42_DIR)/include -I$(LIBFT_DIR)/include
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address

LFLAGS := -L$(MLX42_DIR)/build -lmlx42 -L$(LIBFT_DIR) -lft
ifeq ($(shell uname -s),Darwin)			# Mac
	LFLAGS := $(LFLAGS) -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
else ifeq ($(shell uname -s),Linux)		# Linux
	LFLAGS := $(LFLAGS) -lglfw -ldl -pthread -lm
endif

_DEBUG := 0
ifeq ($(_DEBUG),1)
	CFLAGS := $(CFLAGS) -DDEBUG=1
endif

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
RESET = \x1b[0m
YELLOW = \x1b[33;01m

all: $(MLX42) $(LIBFT) $(NAME)

$(MLX42):
	cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	@$(MAKE) -C $(MLX42_DIR)/build -j4 --quiet
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(NAME): $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJECTS) $(LFLAGS) -o $(NAME)
	@printf "(fdf) $(GREEN)Created program $(NAME)$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@printf "(fdf) $(BLUE)Created object $$(basename $@)$(RESET)\n"

clean:
	@$(MAKE) clean -C $(MLX42_DIR)/build -j4 --quiet
	@$(MAKE) clean -C $(LIBFT_DIR) --quiet
	@for file in $(shell find $(OBJ_DIR) -type f -name '*.o'); do \
		rm -f $$file;	\
		printf "(fdf) $(RED)Removed object $$(basename $$file)$(RESET)\n"; \
	done

fclean: clean
	@$(MAKE) clean/fast -C $(MLX42_DIR)/build -j4 --quiet
	@$(MAKE) fclean -C $(LIBFT_DIR) --quiet
	@-rm -f $(NAME)
	@printf "(fdf) $(RED)Removed program $(NAME)$(RESET)\n"

re: fclean all

.PHONY: all, clean, fclean, re
