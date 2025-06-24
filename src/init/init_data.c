/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:04:52 by rureshet          #+#    #+#             */
/*   Updated: 2025/06/24 14:40:20 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_map(t_map *map)
{
	map->content = NULL;
	map->north = NULL;
	map->east = NULL;
	map->south = NULL;
	map->west = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->valid_content = true;
	map->map_width = 0;
	map->initial_position = '1';
	map->initial_pos_x = 0;
	map->initial_pos_y = 0;
	map->index = 0;
	map->size = TEX_SIZE;
	map->step = 0.0;
	map->pos = 0.0;
	map->x = 0;
	map->y = 0;
	map->size_l = 0;
	map->i = 0;
	map->j = 0;
}

void	init_img_zero(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 4;
	ray->map_y = 4;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_player(t_player *player, t_map *map)
{
	player->dir = map->initial_position;
	player->pos_x = map->initial_pos_x + 0.5;
	player->pos_y = map->initial_pos_y + 0.5;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->win_width = WIN_WIDTH;
	game->win_heght = WIN_HEIGHT;
	init_player(&game->player, &game->mapinfo);
	init_ray(&game->ray);
	game->texture_pixels = NULL;
	game->textures = NULL;
}
