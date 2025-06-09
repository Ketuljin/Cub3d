/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:14:33 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/09 14:32:11 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	search_for_start(t_map *map, char *stock)
{
	int	i;

	i = map->i;
	while (stock[i] && stock[i] != '1')
	{
		if (stock[i] == '\n')
			map->i = i + 1;
		i++;
	}
}

int	count_line(t_map *map, char *stock)
{
	int	stop;
	int	i;

	stop = 0;
	i = map->i;
	while (stock[i])
	{
		if (stock[i] == '\n')
			stop++;
		i++;
	}
	if (i > map->i && stock[i - 1] != '\n')
		stop++;
	return (stop);
}

void	create_map(t_map *map, char *stock)
{
	int	i;
	int	row;
	int	col;

	col = 0;
	row = 0;
	i = map->i;
	while (stock[i])
	{
		if (stock[i] == '\n')
		{
			map->content[row][col] = '\0';
			row++;
			col = 0;
		}
		else
		{
			map->content[row][col] = stock[i];
			col++;
		}
		i++;
	}
	map->content[row] = NULL;
}

void	search_for_map(t_map *map, char *stock)
{
	search_for_start(map, stock);
	map->sizeL = count_line(map, stock);
	map->content = malloc((map->sizeL + 1) * sizeof(char *));
	alloc_line(map, stock);
	create_map(map, stock);
	map->i = 0;
	printf("sizeL 2 = %d\n", map->sizeL);
}
