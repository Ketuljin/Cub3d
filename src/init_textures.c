/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:51:10 by rureshet          #+#    #+#             */
/*   Updated: 2025/05/29 21:21:16 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void 	get_texture_index(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			game->mapinfo.index = WEST;
		else
			game->mapinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			game->mapinfo.index = SOUTH;
		else
			game->mapinfo.index = NORTH;
	}
}

void	update_texture_pixels(t_game *game, t_map *map, t_ray *ray, int x)
{
	(void)map;
	(void)x;
	get_texture_index(game, ray);
}

void	init_texture_pixels(t_game *game)
{
	int	i;

	if (game->texture_pixels)
		free_tab((void **)game->texture_pixels);
	game->texture_pixels = ft_calloc(game->win_heght + 1, sizeof * game->texture_pixels);
	if (!game->texture_pixels)
		clean_exit(game, 1);
	i = 0;
	while (i < game->win_heght)
	{
		game->texture_pixels[i] = ft_calloc(game->win_width + 1, sizeof * game->texture_pixels);
		if (!game->texture_pixels[i])
			clean_exit(game, 1);
		i++;
	}

}
