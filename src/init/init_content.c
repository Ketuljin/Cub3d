/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:06:25 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/24 14:24:46 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	rgb_values(char **full_color)
{
	int		r;
	int		g;
	int		b;
	int		j;

	j = 0;
	while (j < 3)
	{
		if (!ft_isnumeric(full_color[j]))
		{
			free_tab((void **)full_color);
			return (-1);
		}
		j++;
	}
	r = ft_atoi(full_color[0]);
	g = ft_atoi(full_color[1]);
	b = ft_atoi(full_color[2]);
	free_tab((void **)full_color);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

static int	verif_floor_ceiling(char *color)
{
	char	**full_color;
	int		color_rgb;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (color[i])
	{
		if (color[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		return (-1);
	full_color = ft_split(color, ',');
	color_rgb = rgb_values(full_color);
	return (color_rgb);
}

static void	verif_useless_content(t_map *map, char *stock)
{
	int	i;
	int	count_line;
	int	word;

	word = 0;
	count_line = 0;
	i = 0;
	while (stock[i] && i != map->i +1)
	{
		if (stock[i] != ' ' && stock[i] != '\t' && stock[i] != '\n')
			word++;
		if (stock[i] == '\n')
		{
			if (word > 0)
				count_line++;
			word = 0;
		}
		i++;
	}
}

static void	color_converter(t_map *map)
{
	if (map->floor != NULL)
		map->floor_color = verif_floor_ceiling(map->floor);
	if (map->ceiling != NULL)
		map->ceiling_color = verif_floor_ceiling(map->ceiling);
	if (map->ceiling_color == -1 || map->floor_color == -1)
		print_err("ERROR/ Problem with color ceil/floor\n", map);
}

void	init_content(t_map *map, int fd)
{
	char	*stock;

	stock = full_line(fd);
	init_map(map);
	search_for_texture(map, stock);
	if (check_error(map, stock))
	{
		free(stock);
		return ;
	}
	verif_file(map);
	verif_useless_content(map, stock);
	color_converter(map);
	search_for_map(map, stock);
	if (map->content == NULL)
	{
		free(stock);
		return ;
	}
	verif_map(map);
	free(stock);
}
