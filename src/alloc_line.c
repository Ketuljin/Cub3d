/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:38:52 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/03 16:31:12 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

static int	line_length(char *stock, int i)
{
	int	len;

	len = 0;
	while (stock[i] && stock[i] != '\n')
	{
		len++;
		i++;
	}
	return (len);
}

static int	alloc_line_content(t_map *map, int line_index, int len)
{
	map->content[line_index] = malloc((len + 1) * sizeof(char));
	if (!map->content[line_index])
		return (0);
	map->content[line_index][len] = '\0';
	if (len > map->map_width)
		map->map_width = len;
	return (1);
}

void	alloc_line(t_map *map, char *stock)
{
	int	i;
	int	line;
	int	len;

	line = 0;
	i = map->i;
	while (stock[i])
	{
		len = line_length(stock, i);
		if (!alloc_line_content(map, line, len))
			return ;
		line++;
		i += len;
		if (stock[i] == '\n')
			i++;
	}
	map->sizel = line;
}
