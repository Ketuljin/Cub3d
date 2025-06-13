/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:25:17 by rureshet          #+#    #+#             */
/*   Updated: 2025/06/13 16:39:19 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	is_valid_pos(t_game *game, double x, double y)
{
	if (x < 1.25 || x >= game->mapinfo.map_width - 1.25)
		return (false);
	if (y < 1.25 || y >= game->mapinfo.size_l - 1.25)
		return (false);
	if (game->mapinfo.content[(int)y][(int)x] == '0')
		return (true);
	return (true);
}

int	validate_move(t_game *game, double new_x, double new_y)
{
	int	move;

	move = 0;
	if (is_valid_pos(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		move = 1;
	}
	if (is_valid_pos(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		move = 1;
	}
	return (move);
}

int	render(t_game *game)
{
	game->player.has_moved += player_move(game);
	if (game->player.has_moved == 0)
		return (0);
	render_raycast(game);
	return (0);
}
