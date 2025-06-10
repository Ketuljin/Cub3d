/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:19:13 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/10 15:49:36 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	count_char(char c, char *color)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (color[i])
	{
		if (color[i] == c)
			j++;
		i++;
	}
	if (j != 2)
		return (-1);
	return (0);
}

int	verif_floor_ceiling(char *color)
{
	char	**full_color;
	int		r;
	int		g;
	int		b;
	int		j;

	j = -1;
	if (count_char(',', color) == -1)
		return (-1);
	full_color = ft_split(color, ',');
	while (++j < 3)
	{
		if (!ft_isnumeric(full_color[j]))
		{
			free_malloc(full_color, 3);
			return (-1);
		}
	}
	r = ft_atoi(full_color[0]);
	g = ft_atoi(full_color[1]);
	b = ft_atoi(full_color[2]);
	free_malloc(full_color, 3);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}
