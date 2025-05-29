/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:59:59 by rureshet          #+#    #+#             */
/*   Updated: 2025/05/29 19:21:19 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_raycasting_info(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

void	set_dda(t_ray *ray, t_player *player)
{
	if(ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if(ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

void	make_dda(t_game *game, t_ray *ray)
{
	int wall_found;

	wall_found = 0;
	while (wall_found == 0)
	{
		if(ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0.25 || ray->map_x < 0.25
			|| ray->map_y > game->mapinfo.sizeL - 0.25
			|| ray->map_x > game->mapinfo.map_width - 1.25)
			break ;
		if (game->map[ray->map_y][ray->map_x] == '1')
			wall_found = 1;
	}
}

void	line_height(t_ray *ray, t_game *game, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(game->win_heght / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + game->win_heght / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->win_heght / 2;
	if (ray->draw_end >= game->win_heght)
		ray->draw_end = game->win_heght -1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

int	raycasting(t_player *player, t_game *game)
{
	t_ray	ray;
	int		x;

	ray = game->ray;
	x = 0;
	while (x < game->win_width)
	{
		init_raycasting_info(x, &game->ray, player);
		set_dda(&game->ray, player);
		make_dda(game, &ray);
		line_height(&game->ray, game, player);
		x++;
	}
	return (SUCCESS);
}

void	render_raycast(t_game *game)
{
	init_texture_pixels(game);
	init_ray(&game->ray);
	raycasting(&game->player, game);
}
