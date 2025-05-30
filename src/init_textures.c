/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:51:10 by rureshet          #+#    #+#             */
/*   Updated: 2025/05/30 18:55:43 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void 	get_texture_index(t_game *game, t_ray *ray)
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
	int y;
	int color;

	get_texture_index(game, ray);
	map->x = (int)(ray->wall_x * map->size);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1 && ray->dir_y > 0))
		map->x = map->size - map->x - 1;
	map->step = 1.0 * map->size / ray->line_height;
	map->pos = (ray->draw_start - game->win_heght / 2 + ray->line_height / 2) * map->step;
	y =  ray->draw_start;
	while (y < ray->draw_end)
	{
		map->y = (int)map->pos & (map->size - 1);
		map->pos += map->step;
		color = game->textures[map->index][map->size * map->y + map->x];
		if (color > 0)
			game->texture_pixels[y][x] = color;
		y++;
	}
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
