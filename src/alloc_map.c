/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:14:33 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/10 15:03:12 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

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
	if (i > map->i && stock[i -1] != '\n')
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
}

void	search_for_map(t_map *map, char *stock)
{
	map->sizel = count_line(map, stock);
	map->content = malloc((map->sizel) * sizeof(char *));
	if (map->content == NULL)
	{
		print_err("ERROR/ malloc problem with map->content\n", map);
		free(stock);
		return ;
	}
	alloc_line(map, stock);
	if (map->content == NULL)
	{
		return ;
	}
	create_map(map, stock);
	map->i = 0;
}
