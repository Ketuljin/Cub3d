/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:16:53 by rureshet          #+#    #+#             */
/*   Updated: 2025/05/20 15:48:34 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return(SUCCESS);
}

void	init_map_test(t_map *map)
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

void	init_game_test(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->win_width = WIN_WIDTH;
	game->win_heght = WIN_HEIGHT;
	init_map_test(&game->map);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_game game;

	init_game_test(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return(FAILURE);
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game.win)
		return(FAILURE);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return(SUCCESS);
}
