/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:13:43 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/24 14:25:30 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

int	get_content(char c, t_map *map, int l, int i)
{
	if (c != ' ' && c != '0' && c != '1'
		&& c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (map->initial_position != '1')
		{
			print_err("ERROR/ Too much player\n", map);
			return (0);
		}
		else
		{
			map->initial_pos_x = i;
			map->initial_pos_y = l;
			map->initial_position = c;
			map->content[l][i] = '0';
		}
	}
	return (1);
}
