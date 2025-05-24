/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:16:53 by rureshet          #+#    #+#             */
/*   Updated: 2025/05/24 18:27:28 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return(SUCCESS);
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
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

void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	init_map(t_map *mapinfo)
{
	char *content_test[] = {
		"11111",
		"10001",
		"1N011",
		"10001",
		"11111",
		NULL
	};

	mapinfo->content = content_test;
	mapinfo->sizeL = 0;
	mapinfo->valid_content = true;
	mapinfo->north = NULL;
	mapinfo->south = NULL;
	mapinfo->east = NULL;
	mapinfo->west = NULL;
	mapinfo->floor = NULL;
	mapinfo->ceiling = NULL;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->win_width = WIN_WIDTH;
	game->win_heght = WIN_HEIGHT;
	init_map(&game->mapinfo);
	game->map = NULL;
}
int	key_press_handle(int key, t_game *game)
{
	(void)game;
	if (key == XK_Left)
		printf("<--\n");
	else if (key == XK_Right)
		printf("-->\n");
	else if (key == XK_w)
		printf("W\n");
	else if (key == XK_s)
		printf("S\n");
	else if (key == XK_a)
		printf("A\n");
	else if (key == XK_d)
		printf("D\n");
	return(0);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return(FAILURE);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		return(FAILURE);
	mlx_hook(game->win, 17, 0, close_game, &game);
	mlx_hook(game->win, 2, 1L<<0, key_press_handle, game);
	mlx_loop(game->mlx);
	return(SUCCESS);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_game game;

	init_game(&game);
	if(init_mlx(&game) == FAILURE)
		return (FAILURE);
	return(SUCCESS);
}
