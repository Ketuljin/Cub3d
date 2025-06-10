/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:20:28 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/10 14:06:11 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	verif_content(t_map *map)
{
	int	l;
	int	i;

	i = 0;
	l = 0;
	while (map->sizel > l)
	{
		while (map->content[l][i] != '\0')
		{
			if (!get_content(map->content[l][i], map, l, i))
				print_err("ERROR/ Your map can have : 10NSWE\n", map);
			i++;
		}
		l++;
		i = 0;
	}
}

void	verif_wall(t_map *map)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (y < map->sizel - 1)
	{
		while (map->content[y][i])
		{
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

void	verif_map(t_map *map)
{
	if (map->content == NULL)
		return ;
	verif_content(map);
	if (map->initial_position == '1')
		print_err("ERROR/ You got no initial pos for your start", map);
	verif_wall(map);
}
