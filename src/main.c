/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:16:53 by rureshet          #+#    #+#             */
/*   Updated: 2025/05/22 13:46:51 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return(SUCCESS);
}

void	init_map(t_map *map)
{
	char *content_test[] = {
		"11111",
		"10001",
		"1N011",
		"10001",
		"11111",
		NULL
	};

	map->content = content_test;
	map->sizeL = 0;
	map->valid_content = true;
	map->north = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
}

void	init_game(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return ;
	game->mlx = NULL;
	game->win = NULL;
	game->win_width = WIN_WIDTH;
	game->win_heght = WIN_HEIGHT;
	init_map(game->map);
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
