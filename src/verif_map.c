/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:20:28 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/06 17:34:25 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	verif_content(t_map *map)
{
	int	l;
	int	i;

	i = 0;
	l = 0;
	while (map->sizeL > l)
	{
		while (map->content[l][i] != '\0')
		{
			if (!get_content(map->content[l][i], map, l, i))
				print_err("ERROR/ Problem with map 1", map);
			i++;
		}
		l++;
		i = 0;
	}
}

void	wall_alone(t_map *map, int y, int i)
{
	int	check;

	check = 0;
	if (y < map->sizeL && i < (int)ft_strlen(map->content[y + 1]))
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
		print_err("ERROR/ Problem with map 2", map);
}

void	verif_wall(t_map *map)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (y < map->sizeL - 1)
	{
		while (map->content[y][i])
		{
			if (map->content[y][i] != '1' && map->content[y][i] != ' ')
				wall_around(map, y, i);
			if (map->content[y][i] == '1')
				wall_alone(map, y, i);
			if (map->valid_content == false)
				break ;
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
		print_err("ERROR/ Problem with map 3", map);
	verif_wall(map);
}
