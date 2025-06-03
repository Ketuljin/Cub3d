/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:40:27 by rureshet          #+#    #+#             */
/*   Updated: 2025/06/03 12:26:18 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int player_move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVESPEED;
	return(validate_move(game, new_x, new_y));
}

int player_move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVESPEED;
	return(validate_move(game, new_x, new_y));
}

int player_move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * MOVESPEED;
	new_y = game->player.pos_y - game->player.dir_x * MOVESPEED;
	return(validate_move(game, new_x, new_y));
}

int	player_move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * MOVESPEED;
	new_y = game->player.pos_y + game->player.dir_x * MOVESPEED;
	return(validate_move(game, new_x, new_y));
}

int	player_rotate(t_game *game, double rotdir)
{
	t_player *player;
	double	tmp_dir_x;
	double	tmp_plane_x;
	double	rotation;
	
	rotation = rotdir * ROTSPEED;
	player = &game->player;
	tmp_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotation) - player->dir_y * sin(rotation);
	player->dir_y = tmp_dir_x * sin(rotation) + player->dir_y * cos(rotation);
	tmp_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotation) - player->plane_y * sin(rotation);
	player->plane_y = tmp_plane_x * sin(rotation) + player->plane_y * cos(rotation);
	return (1);
}

int	player_move(t_game *game)
{
	int	moved;
	
	moved = 0;
	if (game->player.move_y == 1)
		moved += player_move_forward(game);
	if (game->player.move_y == -1)
		moved += player_move_backward(game);
	if (game->player.move_x == -1)
		moved += player_move_left(game);
	if (game->player.move_x == 1)
		moved += player_move_right(game);
	if (game->player.rotate != 0)
		moved += player_rotate(game, game->player.rotate);
	return (moved);
}

