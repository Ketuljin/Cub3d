/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:57:09 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/12 17:08:26 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	while (stock[i] && stock[i] != '\n' && stock[i] != ' ' && stock[i] != '\t')
	{
		i++;
		len++;
	}
	return (len);
}

static int	verif_end_line(char	*stock, int i)
{
	while (stock[i] && stock[i] != '\n')
	{
		if (stock[i] != ' ' && stock[i] != '\t')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static char	*copy_word(char *stock, int start, int len, t_map *map)
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
			break;
	}
	word[len] = '\0';
	
	if (!verif_end_line(stock, start + j))
	{
		free(word);
		print_err("ERROR/ Wrong input in the file\n", map);
		return (NULL);
	}
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
	file_name = copy_word(stock, start, len, map);
	if (!file_name)
		return (NULL);
	if (map->i < start + len)
		map->i = start + len;
	return (file_name);
}




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
			break;
	}
	word[len] = '\0';
	
	/*
	if (!verif_end_line(stock, start + j))
	{
		free(word);
		print_err("ERROR/ Wrong input in the file\n", map);
		return (NULL);
	}*/
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
