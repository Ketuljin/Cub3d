/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:09:41 by rureshet          #+#    #+#             */
/*   Updated: 2025/06/11 13:10:11 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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