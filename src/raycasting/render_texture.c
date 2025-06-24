/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:40:59 by rureshet          #+#    #+#             */
/*   Updated: 2025/06/24 14:41:26 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_texture_image(t_game *game, t_img *img, char *path)
{
	init_img_zero(img);
	img->img = mlx_xpm_file_to_image(game->mlx, path, &game->mapinfo.size,
			&game->mapinfo.size);
	if (img->img == NULL)
	{
		print_err("ERROR/ Bad texture file\n", &game->mapinfo);
		clean_exit(game, 1);
	}
	img->addr = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
}

static int	*xpm_to_img(t_game *game, char *path)
{
	t_img	img;
	int		*buffer;
	int		x;
	int		y;

	init_texture_image(game, &img, path);
	buffer = ft_calloc(1, sizeof * buffer * game->mapinfo.size
			* game->mapinfo.size);
	if (!buffer)
		clean_exit(game, 1);
	y = 0;
	while (y < game->mapinfo.size)
	{
		x = 0;
		while (x < game->mapinfo.size)
		{
			buffer[y * game->mapinfo.size + x] = img.addr[y
				* game->mapinfo.size + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img.img);
	return (buffer);
}

void	init_textutes(t_game *game)
{
	game->textures = ft_calloc(5, sizeof * game->textures);
	if (!game->textures)
		clean_exit(game, 1);
	game->textures[NORTH] = xpm_to_img(game, game->mapinfo.north);
	game->textures[SOUTH] = xpm_to_img(game, game->mapinfo.south);
	game->textures[EAST] = xpm_to_img(game, game->mapinfo.east);
	game->textures[WEST] = xpm_to_img(game, game->mapinfo.west);
}
