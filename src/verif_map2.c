/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:13:43 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/09 14:09:38 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	value_pos(t_map *map, int y, int i)
{
	int	x;

	x = 0;
	while (map->content[y][x])
	{
		if (i == x)
			return (map->content[y][x]);
		x++;
	}
	return ('\0');
}

void	empty_line(t_map *map, int y, int i)
{
	int	x;

	x = 0;
	while (map->content[y][x] != '\0')
	{
		if (map->content[y][x] != ' ')
			break ;
		x++;
	}
	if (map->content[y][x] == '\0' || map->content[y][x] == ' ')
		print_err("ERROR/ Problem with map 4", map);
	while (y < map->sizeL - 1)
	{
		if (value_pos(map, y, i) != ' ')
			break ;
		y++;
	}
	if (map->content[y][i] == '\0' || map->content[y][i] == ' ')
		print_err("ERROR/ Problem with map 5", map);
}

int	get_content(char c, t_map *map, int l, int i)
{
	if (c != ' ' && c != '0' && c != '1'
		&& c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (map->initial_position != '1')
		{
			print_err("ERROR/ Problem with map 6", map);
			return (0);
		}
		else
		{
			map->initial_posX = i;
			map->initial_posY = l;
			map->initial_position = c;
		}
	}
	return (1);
}
