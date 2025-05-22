/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:14:33 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/22 12:37:30 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	search_for_start(t_map *map, char *stock)
{
	int	i;

	i = map->i;
	while (stock[i] && stock[i] != '1')
	{
		if (stock[i] == '\n')
			map->i = i+1;
		i++;
	}
}

int	count_line(t_map *map, char *stock)
{
	int stop;
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

void alloc_line(t_map *map, char *stock)
{
	int i = map->i;
	int line = 0;
	int len = 0;

	while (stock[i]) {
		if (stock[i] == '\n') {
			map->content[line] = malloc((len + 1) * sizeof(char));
			if (!map->content[line])
				return;
			line++;
			len = 0;
		} else {
			len++;
		}
		i++;
	}
	if (len > 0) {
		map->content[line] = malloc((len + 1) * sizeof(char));
		if (!map->content[line])
			return;
	}
}


void create_map(t_map *map, char *stock)
{
	int i = map->i;
	int row = 0;
	int col = 0;

	while (stock[i]) {
		if (stock[i] == '\n') {
			map->content[row][col] = '\0';
			row++;
			col = 0;
		} else {
			map->content[row][col] = stock[i];
			col++;
		}
		i++;
	}
}

void	search_for_map(t_map *map, char *stock)
{
	search_for_start(map, stock);
	map->sizeL = count_line(map, stock);
	map->content = malloc((map->sizeL) * sizeof(char *));
	alloc_line(map, stock);
	create_map(map, stock);
	map->i = 0;
}