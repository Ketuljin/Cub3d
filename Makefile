# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 07:51:49 by jkerthe           #+#    #+#              #
#    Updated: 2025/06/24 14:02:44 by rureshet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = gcc
CFLAGS  = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
MLX_DIR = minilibx-linux

SRCS =	$(SRC_DIR)/init/init_content.c \
		$(SRC_DIR)/init/init_data.c \
		$(SRC_DIR)/init/init_mlx.c \
		$(SRC_DIR)/init/init_player_dir.c \
		$(SRC_DIR)/init/init_textures.c \
		$(SRC_DIR)/parsing/alloc_line.c \
		$(SRC_DIR)/parsing/alloc_map.c \
		$(SRC_DIR)/parsing/get_texture.c \
		$(SRC_DIR)/parsing/stock_color.c \
		$(SRC_DIR)/parsing/stock_texture.c \
		$(SRC_DIR)/parsing/verif_file.c \
		$(SRC_DIR)/parsing/verif_map_utils.c \
		$(SRC_DIR)/parsing/verif_map.c \
		$(SRC_DIR)/parsing/wall_around.c \
		$(SRC_DIR)/raycasting/player_move.c \
		$(SRC_DIR)/raycasting/player_rotate.c \
		$(SRC_DIR)/raycasting/raycasting.c \
		$(SRC_DIR)/raycasting/render_frame.c \
		$(SRC_DIR)/raycasting/render_texture.c \
		$(SRC_DIR)/raycasting/render.c \
		$(SRC_DIR)/utils/ft_atoi.c \
		$(SRC_DIR)/utils/ft_isnumeric.c \
		$(SRC_DIR)/utils/ft_split.c \
		$(SRC_DIR)/utils/ft_strdup.c \
		$(SRC_DIR)/utils/ft_substr.c \
		$(SRC_DIR)/utils/full_line.c \
		$(SRC_DIR)/utils/get_next_line_utils.c \
		$(SRC_DIR)/utils/get_texture_utils.c \
		$(SRC_DIR)/errors.c \
		$(SRC_DIR)/exit.c \
		$(SRC_DIR)/free_game.c \
		$(SRC_DIR)/main.c \

OBJS = $(SRCS: $(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lX11 -lXext -lbsd -lm

all: mlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME);

re: fclean all

mlx:
	make -C $(MLX_DIR)

.PHONY: all clean fclean re mlx
