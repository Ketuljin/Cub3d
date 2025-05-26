/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:12:14 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/26 13:08:43 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	check_wall(t_map *map, int y, int i)
{
	int j;

	j = 0;
	while (map->content[y][j])
	{
		if (j == i && map->content[y][j] == ' ')
			map->valid_content = false;
		if (j == i && map->content[y][j] == '1')
			return (0);		
		j++;
	}
	return (1);
}

void	wall_top(t_map *map, int y, int i)
{
	while (y >= 0)
	{
		if (!check_wall(map, y, i))
			return ;
		y--;
	}
	map->valid_content = false;
}

void	wall_bot(t_map *map, int y, int i)
{
	while (y < map->sizeL-1)
	{
		if (!check_wall(map, y, i))
			return ;
		y++;
	}
	map->valid_content = false;
}

void	wall_left(t_map *map, int y, int i)
{
	while (i >= 0)
	{
		if (!check_wall(map, y, i))
			return ;
		i--;
	}
	map->valid_content = false;
}

void	wall_right(t_map *map, int y, int i)
{
	while (map->content[y][i] != '\0')
	{
		if (map->content[y][i] != '1')
			return ;
		i++;
	}
	map->valid_content = false;
}


void	wall_around(t_map *map, int y, int i)
{
	wall_top(map, y, i);
	wall_bot(map, y, i);
	wall_left(map, y, i);
	wall_right(map, y, i);
}