/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:20:28 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/12 18:15:39 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	verif_content(t_map *map)
{
	int	l;
	int	i;

	i = 0;
	l = 0;
	if (map->sizeL <= 2)
		print_err("ERROR/ Map too small\n", map);
	while (l < map->sizeL-1)
	{
		while (map->content[l][i] != '\0')
		{
			if (!get_content(map->content[l][i], map, l, i))
				print_err("ERROR/ In your map you can only have : 10SWEN\n", map);
			i++;
		}
		l++;
		i = 0;
	}
}

static void	verif_wall(t_map *map)
{
	int	i;
	int	y;

	y = 0;
	i = 0;

	while (y < map->sizeL - 1)
	{
		while (map->content[y][i])
		{
			if (y >= map->j)
				break ;
			if (map->content[y][i] != '1' && map->content[y][i] != ' ')
				wall_around(map, y, i);
			if (map->valid_content == false)
				break ;
			i++;
		}
		i = 0;
		y++;
	}
	
}

void	last_map_content(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map->sizeL > j)
	{
		while (map->content[j][i])
		{
			if (map->content[j][i] != '\t' && map->content[j][i] != ' ' && map->content[j][i] != '\n')
			{
				map->i = i;
				map->j = j;
			}
			i++;
		}
		i = 0;
		j++;
	}
	map->j++;
}

void	empty_line(t_map *map)
{
	int	x;
	int empty;
	int y;

	y = 0;
	empty = 0;
	x = 0;
	while (y < map->j)
	{
		while (map->content[y][x] != '\0')
		{
			if (map->content[y][x] !=  ' ' && map->content[y][x] != '\n' && map->content[y][x] != '\t')
				empty = 1;
			x++;
		}
		if (empty == 0)
			print_err("ERROR/ You have an empty line in your map\n", map);
		empty = 1;
		x = 0;
		y++;
	}
}

void	verif_map(t_map *map)
{
	last_map_content(map);
	empty_line(map);
	verif_content(map);
	if (map->initial_position == '1')
		print_err("ERROR/ No player\n", map);
	verif_wall(map);
}
