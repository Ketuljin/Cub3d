/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:57:09 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/03 15:18:17 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

static int	skip_spaces_newlines(char *stock, int i)
{
	while (stock[i] && (stock[i] == ' ' || stock[i] == '\n'))
		i++;
	return (i);
}

static int	word_length(char *stock, int i)
{
	int	len;

	len = 0;
	while (stock[i] && stock[i] != ' ' && stock[i] != '\n')
	{
		i++;
		len++;
	}
	return (len);
}

static char	*copy_word(char *stock, int start, int len)
{
	char	*word;
	int		j;

	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = stock[start + j];
		j++;
	}
	word[len] = '\0';
	return (word);
}

char	*stock_texture(char *stock, int i, t_map *map)
{
	int		start;
	int		len;
	char	*file_name;

	i += 2;
	if (stock[i] != ' ')
		return (NULL);
	i = skip_spaces_newlines(stock, i);
	start = i;
	len = word_length(stock, i);
	file_name = copy_word(stock, start, len);
	if (!file_name)
		return (NULL);
	if (map->i < start + len)
		map->i = start + len;
	return (file_name);
}
