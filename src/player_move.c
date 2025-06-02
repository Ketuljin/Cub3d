/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:40:27 by rureshet          #+#    #+#             */
/*   Updated: 2025/06/02 16:38:30 by rureshet         ###   ########.fr       */
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
	return (moved);
}

