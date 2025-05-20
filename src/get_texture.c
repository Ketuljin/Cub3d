/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:12:51 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/20 15:15:28 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	search_for_north(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'N' && stock[i+1] == 'O')
		{
			
			if (map->north != NULL)
				map->valid_content = false;
			else
				map->north = stock_texture(stock, i);
		}
		i++;
	}
	if (map->north == NULL)
		map->valid_content = false;
}
void	search_for_south(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'S' && stock[i+1] == 'O')
		{
			if (map->south != NULL)
				map->valid_content = false;
			else
				map->south = stock_texture(stock, i);
		}
		i++;
	}
	if (map->south == NULL)
		map->valid_content = false;
}
void	search_for_west(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'W' && stock[i+1] == 'E')
		{
			if (map->west != NULL)
				map->valid_content = false;
			else
				map->west = stock_texture(stock, i);
		}
		i++;
	}
	if (map->west == NULL)
		map->valid_content = false;
}
void	search_for_east(t_map *map, char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == 'E' && stock[i+1] == 'A')
		{
			if (map->east != NULL)
				map->valid_content = false;
			else
				map->east = stock_texture(stock, i);
		}
		i++;
	}
	if (map->east == NULL)
		map->valid_content = false;
}


