# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 13:09:18 by pollivie          #+#    #+#              #
#    Updated: 2024/07/23 13:09:18 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
# CFLAGS = -Wall -Werror -Wextra -fno-omit-frame-pointer -g3
CFLAGS = -Wall -Werror -Wextra -Ofast -mtune=native

# CFLAGS = -Wall                           \
#          -Werror                         \
#          -Wextra                         \
#          -fno-omit-frame-pointer         \
#          -g3                             \
#          -fsanitize=address              \
#          -fsanitize=undefined            \
#          -Wno-unused-parameter           \
#          -Wno-unused-variable            \
#          -Wshadow                        \
#          -Wimplicit-fallthrough          \
#          -Wmissing-include-dirs          \
#          -Wswitch-enum                   \
#          -Wnull-dereference              \
#          -DLOG_USE_COLOR                 \

LDFLAGS = -Lmlx -lmlx -lX11 -lXext -lbsd -lm
SRC_DIR = src
INCLUDE_DIR = include
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
OBJ_DIR = .obj
BIN = cub3D

# Find all .c files in SRC_DIR and its subdirectories
SRCS = $(shell find $(SRC_DIR) -type f -name '*.c')
# Generate corresponding object file paths in OBJ_DIR
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Rules
all: $(MLX_LIB) $(BIN)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

# Compile .c files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

# Link object files to create the binary
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean

# Clean everything
fclean: clean
	rm -f $(BIN)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
