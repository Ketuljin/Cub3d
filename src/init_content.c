/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:06:25 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/20 15:18:38 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	*stock_texture(char *stock, int i)
{
	int		start;
	int		count;
	char	*file_name;
	int		j;

	j = 0;
	count = 0;
	i += 2;
	if (stock [i] != ' ')
		return (NULL);
	while (stock[i] && (stock[i] == ' ' || stock[i] == '\n'))
		i++;
	start = i;
	while (stock[i] && stock[i] != ' ' && stock[i] != '\n')
	{
		i++;
		count++;
	}
	file_name = malloc((count + 1) * sizeof(char));
	while (j < count)
	{
		file_name[j] = stock[start + j];
		j++;
	}
	file_name[count] = '\0';
	return (file_name);
}

void	init_map(t_map *map)
{
	map->ceiling = NULL;
	map->north = NULL;
	map->content = NULL;
	map->east = NULL;
	map->south = NULL;
	map->floor = NULL;
	map->west = NULL;
	map->valid_content = true;
}

void	free_all(t_map *map)
{
	free(map->ceiling);
	free(map->north);
	free(map->content);
	free(map->east);
	free(map->south);
	free(map->floor);
	free(map->west);
}

void	init_content(t_map *map, int fd)
{
	char	*stock;

	stock = full_line(fd);
	init_map(map);
	search_for_texture(map, stock);
	if (map->valid_content == false)
	{
		free (stock);
		free_all(map);
		return ;
	}
}