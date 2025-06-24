/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:10:48 by rureshet          #+#    #+#             */
/*   Updated: 2025/06/24 14:40:25 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	key_press_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_game(game);
	if (key == XK_Left)
		game->player.rotate -= 1;
	if (key == XK_Right)
		game->player.rotate += 1;
	if (key == XK_w)
		game->player.move_y = 1;
	if (key == XK_a)
		game->player.move_x = -1;
	if (key == XK_s)
		game->player.move_y = -1;
	if (key == XK_d)
		game->player.move_x = 1;
	return (0);
}

static int	key_release_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_game(game);
	if (key == XK_Left && game->player.rotate <= 1)
		game->player.rotate = 0;
	if (key == XK_Right && game->player.rotate >= -1)
		game->player.rotate = 0;
	if (key == XK_w && game->player.move_y == 1)
		game->player.move_y = 0;
	if (key == XK_a && game->player.move_x == -1)
		game->player.move_x += 1;
	if (key == XK_s && game->player.move_y == -1)
		game->player.move_y = 0;
	if (key == XK_d && game->player.move_x == 1)
		game->player.move_x -= 1;
	return (0);
}

void	listener(t_game *game)
{
	mlx_hook(game->win, 17, 0L, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, key_press_handle, game);
	mlx_hook(game->win, 3, 1L << 1, key_release_handle, game);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (FAILURE);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		return (FAILURE);
	return (SUCCESS);
}
