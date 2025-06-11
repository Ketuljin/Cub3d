/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:06:25 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/11 13:02:08 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_map(t_map *map)
{
	map->content = NULL;
	map->north = NULL;
	map->east = NULL;
	map->south = NULL;
	map->west = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	map->valid_content = true;
	map->map_width = 0;
	map->initial_position = '1';
	map->initial_posX = 0;
	map->initial_posY = 0;
	map->index = 0;
	map->size = TEX_SIZE;
	map->step = 0.0;
	map->pos = 0.0;
	map->x = 0;
	map->y = 0;
	map->sizeL = 0;
	map->i = 0;
}

static void	verif_file(t_map *map)
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

static int	verif_floor_ceiling(char *color)
{
	char	**full_color;
	int		r;
	int		g;
	int		b;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (color[i])
	{
		if (color[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		return (-1);
	full_color = ft_split(color, ',');
	j = 0;
	while (j < 3)
	{
		if (!ft_isnumeric(full_color[j]))
		{
			free_tab((void **)full_color);
			return (-1);
		}
		j++;
	}
	r = ft_atoi(full_color[0]);
	g = ft_atoi(full_color[1]);
	b = ft_atoi(full_color[2]);
	free_tab((void **)full_color);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

static void	verif_useless_content(t_map *map, char *stock)
{
	int	i;
	int	count_line;
	int word;

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
		print_err("ERROR/ wrong input\n", map);
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
		print_err("ERROR/ Problem with color ceil/floor\n", map);
	search_for_map(map, stock);
	verif_map(map);
	free(stock);
}
