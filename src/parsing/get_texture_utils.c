/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:12:51 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/24 14:40:45 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	search_for_north(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'N' && stock[i + 1] == 'O')
		{
			if (map->north != NULL)
				print_err("Error/ 2 or more assignements for north\n", map);
			else
				map->north = stock_texture(stock, i, map);
		}
		i++;
	}
}

void	search_for_south(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'S' && stock[i + 1] == 'O')
		{
			if (map->south != NULL)
				print_err("Error/ 2 or more assignements for south\n", map);
			else
				map->south = stock_texture(stock, i, map);
		}
		i++;
	}
}

void	search_for_west(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'W' && stock[i + 1] == 'E')
		{
			if (map->west != NULL)
				print_err("Error/ 2 or more assignements for west\n", map);
			else
				map->west = stock_texture(stock, i, map);
		}
		i++;
	}
}

void	search_for_east(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'E' && stock[i + 1] == 'A')
		{
			if (map->east != NULL)
				print_err("Error/ 2 or more assignements for east\n", map);
			else
				map->east = stock_texture(stock, i, map);
		}
		i++;
	}
}
