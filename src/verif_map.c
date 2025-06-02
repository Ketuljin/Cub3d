/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:20:28 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/02 15:05:52 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/cub3d.h"


int	get_content(char c, t_map *map)
{
	if (c != ' ' && c != '0' && c != '1'
		&& c != 'N' && c!= 'S' && c!= 'E' && c!= 'W')
		return (0);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (map->initial_position != '1')
			return (0);
		else
			map->initial_position = c;
	}
	return (1);
}

void	verif_content(t_map *map)
{
	int	l;
	int i;

	i = 0;
	l = 0;
	while (map->sizeL> l)
	{
		while (map->content[l][i] != '\0')
		{
			if (!get_content(map->content[l][i], map))
				map->valid_content = false;
			i++;
		}
		l++;
		i = 0;
	}
}

void wall_alone(t_map *map, int y, int i)
{
	int check = 0;

	if (y < map->sizeL  && i < (int)ft_strlen(map->content[y + 1]))
		if (map->content[y + 1][i] != ' ' && map->content[y + 1][i] != '\0')
			check = 1;
	if (y > 0 && i < (int)ft_strlen(map->content[y - 1]))
		if (map->content[y - 1][i] != ' ' && map->content[y - 1][i] != '\0')
			check = 1;
	if (i > 0)
		if (map->content[y][i - 1] != ' ' && map->content[y][i - 1] != '\0')
			check = 1;

	if (i + 1 < (int)ft_strlen(map->content[y]))
		if (map->content[y][i + 1] != ' ' && map->content[y][i + 1] != '\0')
			check = 1;

	if (check == 0)
		map->valid_content = false;
}

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
		map->valid_content = false;
	while (y < map->sizeL-1)
	{
		if (value_pos(map, y, i) != ' ')
			break ;
		y++;
	}
	if (map->content[y][i] == '\0' || map->content[y][i] == ' ')
		map->valid_content = false;
}
void	verif_wall(t_map *map)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (y < map->sizeL-1)
	{
		if (map->content[y][0] == '\0')
			map->valid_content = false;
		while (map->content[y][i])
		{
			if (map->content[y][i] != '1' && map->content[y][i] != ' ')
				wall_around(map, y, i);
			if (map->content[y][i] == '1')
				wall_alone(map, y, i);
			if (map->content[y][i] == ' ')
				empty_line(map, y, i);
			i++;
		}
		i = 0;
		y++;
	}
}

void	verif_map(t_map *map)
{
	verif_content(map);
	if (map->initial_position == '1')
		map->valid_content = false;
	verif_wall(map);
}
