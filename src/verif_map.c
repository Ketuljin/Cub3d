/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:20:28 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/22 14:04:33 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"


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
	while (map->sizeL > l)
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

void	verif_map(t_map *map)
{
	verif_content(map);
	if (map->initial_position == '1')
		map->valid_content = false;
}