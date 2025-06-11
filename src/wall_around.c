/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:12:14 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/11 13:26:35 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_wall(t_map *map, int y, int i)
{
	int	j;

	j = 0;
	while (map->content[y][j])
	{
		if (j == i && map->content[y][j] == ' ')
			print_err("ERROR/ Problem with map 7", map);
		if (j == i && map->content[y][j] == '1')
			return (0);
		j++;
	}
	if (j < i)
	{
		print_err("ERROR/ Problem with map 8", map);
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
	while (y < map->sizeL)
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
		print_err("ERROR/ Problem with map 9", map);
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
		print_err("ERROR/ Problem with map 10", map);
}

void	wall_around(t_map *map, int y, int i)
{
	wall_vertical(map, y, i);
	wall_horizontal(map, y, i);
}
