/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:14:33 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/24 14:25:09 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	search_for_start(t_map *map, char *stock)
{
	int	i;

	i = map->i;
	while (stock[i] && stock[i] != '1' && stock[i] != '0')
	{
		if (stock[i] == '\n')
			map->i = i + 1;
		i++;
	}
	if (stock[i] == '\0')
		map->i = -1;
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
	if (stock[i - 1] != '\n')
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
	if (stock[i] == '\0' && stock [i - 1] != '\n')
		row++;
	map->content[row] = NULL;
}

void	search_for_map(t_map *map, char *stock)
{
	search_for_start(map, stock);
	if (map->i == -1)
	{
		print_err("ERROR/ There is no map", map);
		return ;
	}
	map->size_l = count_line(map, stock);
	map->content = malloc((map->size_l +1) * sizeof(char *));
	if (!map->content)
		return ;
	alloc_line(map, stock);
	create_map(map, stock);
	map->i = 0;
}
