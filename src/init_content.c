/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:06:25 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/10 15:39:56 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include <string.h>

void	init_map(t_map *map)
{
	map->ceiling = NULL;
	map->ceiling_color = 0;
	map->north = NULL;
	map->content = NULL;
	map->east = NULL;
	map->south = NULL;
	map->floor = NULL;
	map->floor_color = 0;
	map->west = NULL;
	map->valid_content = true;
	map->initial_position = '1';
	map->initial_posx = 0;
	map->initial_posy = 0;
	map->map_width = 0;
	map->i = 0;
	map->first_x = 0;
}

int	extention_texture(char	*str)
{
	char	*xml;
	char	*ext;

	xml = ".xml";
	ext = ft_strrchr(str, '.');
	if (ext == NULL)
		return (0);
	if (strcmp(ext, xml) == 0)
		return (1);
	return (0);
}

void	verif_file(t_map *map)
{
	if (map->valid_content == false)
		return ;
	if (access(map->north, R_OK) != 0 || !extention_texture(map->north))
		print_err("Error/ North: No such file or directory\n", map);
	if (access(map->south, R_OK) != 0 || !extention_texture(map->south))
		print_err("Error/ South: No such file or directory\n", map);
	if (access(map->east, R_OK) != 0 || !extention_texture(map->east))
		print_err("Error/ East: No such file or directory\n", map);
	if (access(map->west, R_OK) != 0 || !extention_texture(map->west))
		print_err("Error/ West: No such file or directory\n", map);
}

void	verif_useless_content(t_map *map, char *stock)
{
	int	i;
	int	count_line;
	int	word;

	word = 0;
	count_line = 0;
	i = 0;
	while (stock[i] && i != map->i +1)
	{
		if (stock[i] != ' ' && stock[i] != '\t' && stock[i] != '\n')
			word++;
		if (stock[i] == '\n')
		{
			if (word > 0)
				count_line++;
			word = 0;
		}
		i++;
	}
	if (count_line > 6)
		print_err("ERROR/ Too much content in your file.cub\n", map);
}

void	init_content(t_map *map, int fd)
{
	char	*stock;

	stock = full_line(fd);
	init_map(map);
	search_for_texture(map, stock);
	verif_file(map);
	verif_useless_content(map, stock);
	if (map->floor != NULL)
		map->floor_color = verif_floor_ceiling(map->floor);
	if (map->ceiling != NULL)
		map->ceiling_color = verif_floor_ceiling(map->ceiling);
	if (map->ceiling_color == -1 || map->floor_color == -1)
		print_err("ERROR/ Wrong input for ceilling/floor\n", map);
	search_for_map(map, stock);
	verif_map(map);
	free(stock);
}
