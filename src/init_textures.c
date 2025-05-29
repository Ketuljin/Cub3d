/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:51:10 by rureshet          #+#    #+#             */
/*   Updated: 2025/05/29 19:10:44 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
