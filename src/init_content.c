/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:06:25 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/29 21:02:09 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/cub3d.h"



void	init_map(t_map *map)
{
	const char	*content_test[] = {
		"11111",
		"10001",
		"1N011",
		"10001",
		"11111",
		NULL
	};
	int	lines;
	int	i;

	lines = 0;
	while (content_test[lines])
		lines++;

	map->content = malloc(sizeof(char *) * (lines + 1));
	if (!map->content)
		return;
	i = 0;
	while (i < lines)
	{
		map->content[i] = strdup(content_test[i]);
		i++;
	}
	map->content[lines] = NULL;

	map->north = "textures/wolfenstein/colorstone.xpm";
	map->east = "textures/wolfenstein/redbrick.xpm";
	map->south = "textures/wolfenstein/wood.xpm";
	map->west = "textures/wolfenstein/mossy.xpm";

	map->floor = NULL;
	map->floor_color = 0xDC6400;
	map->ceiling = NULL;
	map->ceiling_color = 0xE11E00;

	map->valid_content = true;
	map->initial_position = 'N';
	map->initial_posX = 2;
	map->initial_posY = 1;
	map->index = 0;
	map->size = TEX_SIZE;
	map->step = 0.0;
	map->pos = 0.0;
	map->x = 0;
	map->y = 0;
	map->map_width = 5;
	map->sizeL = lines;
	map->i = 0;
}

// void	init_map(t_map *map)
// {
// 	map->north = NULL;
// 	map->content = NULL;
// 	map->east = NULL;
// 	map->south = NULL;
// 	map->floor = NULL;
// 	map->floor_color = 0;
// 	map->ceiling = NULL;
// 	map->ceiling_color = 0;
// 	map->west = NULL;
// 	map->valid_content = true;
// 	map->initial_position = '1';
// 	map->i = 0;
// }



void	verif_file(t_map *map)
{
	if (map->valid_content == false)
		return ;
	if (access(map->north, R_OK) != 0)
		map->valid_content = false;
	if (access(map->south, R_OK) != 0)
		map->valid_content = false;
	if (access(map->east, R_OK) != 0)
		map->valid_content = false;
	if (access(map->west, R_OK) != 0)
		map->valid_content = false;
	return ;
}

int	verif_floor_ceiling(char *color)
{
	char	**full_color;
	int		r;
	int		g;
	int		b;

	full_color = ft_split(color, ',');
	r = ft_atoi(full_color[0]);
	g = ft_atoi(full_color[1]);
	b = ft_atoi(full_color[2]);
	free_malloc(full_color, 3);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255 )
		return (-1);
	return ((r << 16) | (g << 8) | b );
}

void	init_content(t_map *map, int fd)
{
	char	*stock;
	int		y;

	y = 0;

	stock = full_line(fd);
	init_map(map);
	search_for_texture(map, stock);
	verif_file(map);
	map->floor_color = verif_floor_ceiling(map->floor);
	map->ceiling_color = verif_floor_ceiling(map->ceiling);
	if (map->valid_content == false || map->ceiling_color == -1 ||
		map->floor_color == -1)
	{
		free (stock);
		// free_map(map);
		return ;
	}
	search_for_map(map, stock);
	verif_map(map);
	if (map->valid_content == false)
		printf("PAS BON DUTOUT \n");
	while (y < map->sizeL)
	{
		printf("%s\n", map->content[y]);
		y++;
	}
	free_map(map);
	free_malloc(map->content, map->sizeL);
	free(stock);
}
