/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:24:45 by rureshet          #+#    #+#             */
/*   Updated: 2025/05/31 20:37:21 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_image(t_game *game, t_img *img, int width, int height)
{
	init_img_zero(img);
	img->img = mlx_new_image(game->mlx, width, height);
	if (img->img == NULL)
		clean_exit(game, 1);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->pixel_bits, &img->size_line, &img->endian);
}

void	set_image_pixel(t_img *img, int x, int y, int color)
{
	int	pixel;
	
	pixel = y * (img->size_line / 4) + x;
	img->addr[pixel] = color;
}

void	set_frame_image_pixel(t_game *game, t_img *img, int x, int y)
{
	if (game->texture_pixels[y][x] > 0)
		set_image_pixel(img, x, y, game->texture_pixels[y][x]);
	else if (y < game->win_heght / 2)
		set_image_pixel(img, x, y, game->mapinfo.ceiling_color);
	else if (y < game->win_heght -1)
		set_image_pixel(img, x, y, game->mapinfo.floor_color);
}

void	render_frame(t_game *game)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_image(game, &image, game->win_width, game->win_heght);
	y = 0;
	while (y < game->win_heght)
	{
		x = 0;
		while (x < game->win_width)
		{
			set_frame_image_pixel(game, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
	mlx_destroy_image(game->mlx, image.img);
}