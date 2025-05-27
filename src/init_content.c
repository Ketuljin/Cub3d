/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:06:25 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/27 18:54:56 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/cub3d.h"

void	free_malloc(char **stockf, int l)
{
	int	y;

	y = 0;
	while (y < l)
	{
		free (stockf[y]);
		y++;
	}
	free (stockf);
}

void	init_map(t_map *map)
{
	map->ceiling = NULL;
	map->north = NULL;
	map->content = NULL;
	map->east = NULL;
	map->south = NULL;
	map->floor = NULL;
	map->west = NULL;
	map->valid_content = true;
	map->initial_position = '1';
	map->i = 0;
}

void	free_all(t_map *map)
{
	free(map->ceiling);
	free(map->north);
	free(map->east);
	free(map->south);
	free(map->floor);
	free(map->west);
}

void	verif_file(t_map *map)
{
	if (map->content == false)
		return ;
	if (access(map->north, R_OK) != 0)
		map->content = false;
	if (access(map->south, R_OK) != 0)
		map->content = false;
	if (access(map->east, R_OK) != 0)
		map->content = false;
	if (access(map->west, R_OK) != 0)
		map->content = false;
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
		free_all(map);
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
	free_all(map);
	free_malloc(map->content, map->sizeL);
	free(stock);

}
