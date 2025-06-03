/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:06:25 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/03 16:15:34 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

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
	map->initial_posx = 0;
	map->initial_posy = 0;
	map->map_width = 0;
	map->i = 0;
}

void	verif_file(t_map *map)
{
	if (map->valid_content == false)
		return ;
	if (access(map->north, R_OK) != 0)
		print_err("Error/ North: No such file or directory\n", map);
	if (access(map->south, R_OK) != 0)
		print_err("Error/ South: No such file or directory\n", map);
	if (access(map->east, R_OK) != 0)
		print_err("Error/ East: No such file or directory\n", map);
	if (access(map->west, R_OK) != 0)
		print_err("Error/ West: No such file or directory\n", map);
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
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

void	init_content(t_map *map, int fd)
{
	char	*stock;

	if (fd <= 0)
	{
		print_err("Error/ Wrong name\n", map);
		return ;
	}
	stock = full_line(fd);
	init_map(map);
	search_for_texture(map, stock);
	verif_file(map);
	map->floor_color = verif_floor_ceiling(map->floor);
	map->ceiling_color = verif_floor_ceiling(map->ceiling);
	search_for_map(map, stock);
	verif_map(map);
	free(stock);
}
