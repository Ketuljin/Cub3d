/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:03:46 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/10 15:17:05 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	search_for_floor(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'F' && stock[i + 1] == ' ')
		{
			if (map->floor != NULL)
				print_err("Error/ 2 or more assignements for floor\n", map);
			else
				map->floor = stock_texture(stock, i - 1, map);
		}
		i++;
	}
	if (map->floor == NULL)
		print_err("Error/ No assignement for floor\n", map);
}

void	search_for_ceiling(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'C' && stock[i + 1] == ' ')
		{
			if (map->ceiling != NULL)
				print_err("Error/ 2 or more assignements for ceiling\n", map);
			else
				map->ceiling = stock_texture(stock, i - 1, map);
		}
		i++;
	}
	if (map->ceiling == NULL)
		print_err("Error/ No assignement for ceiling\n", map);
}

void	search_for_texture(t_map *map, char *stock)
{
	search_for_north(map, stock);
	search_for_south(map, stock);
	search_for_west(map, stock);
	search_for_east(map, stock);
	search_for_floor(map, stock);
	search_for_ceiling(map, stock);
}
