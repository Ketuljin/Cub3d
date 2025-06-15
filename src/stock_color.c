/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:47:33 by rureshet          #+#    #+#             */
/*   Updated: 2025/06/14 12:48:02 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*copy_color(char *stock, int start, int len)
{
	char	*word;
	int		j;

	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		if (stock[start + j] && stock[start + j] != '\n')
		{
			word[j] = stock[start + j];
			j++;
		}
		else
			break ;
	}
	word[len] = '\0';
	return (word);
}

static int	color_length(char *stock, int i)
{
	int	len;

	len = 0;
	while (stock[i] && stock[i] != '\n')
	{
		i++;
		len++;
	}
	return (len);
}

char	*stock_color(char *stock, int i, t_map *map)
{
	int		start;
	int		len;
	char	*file_name;

	i += 1;
	if (stock[i] != ' ')
		return (NULL);
	i = skip_spaces_newlines(stock, i);
	start = i;
	len = color_length(stock, i);
	file_name = copy_color(stock, start, len);
	if (!file_name)
		return (NULL);
	if (map->i < start + len)
		map->i = start + len;
	return (file_name);
}
