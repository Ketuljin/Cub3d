/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:12:14 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/24 14:25:41 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_wall(t_map *map, int y, int i)
{
	int	j;

	j = 0;
	if (y >= map->j)
		return (0);
	while (map->content[y][j])
	{
		if (j == i && map->content[y][j] == '1')
			return (0);
		j++;
	}
	if (j < i)
	{
		print_err("ERROR/ Empty line in map\n", map);
		return (1);
	}
	return (1);
}

static void	wall_vertical(t_map *map, int y, int i)
{
	int	j;
	int	check;

	check = 0;
	j = y;
	while (y < map->size_l)
	{
		if (!check_wall(map, y, i))
		{
			check++;
			break ;
		}
		y++;
	}
	while (j >= 0)
	{
		if (!check_wall(map, j, i))
		{
			check++;
			break ;
		}
		j--;
	}
	if (check != 2)
		print_err("ERROR/ You need to close your map with wall\n", map);
}

static void	wall_horizontal(t_map *map, int y, int i)
{
	int	j;
	int	check;

	check = 0;
	j = i;
	while (i >= 0)
	{
		if (!check_wall(map, y, i))
		{
			check++;
			break ;
		}
		i--;
	}
	while (map->content[y][j] != '\0')
	{
		if (map->content[y][j] == '1')
		{
			check++;
			break ;
		}
		j++;
	}
	if (check != 2)
		print_err("ERROR/ You need to close your map with wall\n", map);
}

void	wall_around(t_map *map, int y, int i)
{
	wall_vertical(map, y, i);
	wall_horizontal(map, y, i);
}
