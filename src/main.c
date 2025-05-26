/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:16:53 by rureshet          #+#    #+#             */
/*   Updated: 2025/05/26 11:05:45 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return(SUCCESS);
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
