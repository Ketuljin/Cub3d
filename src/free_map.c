/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:51:55 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/10 14:59:46 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	free_all(t_map *map)
{
	if (map->ceiling != NULL)
		free(map->ceiling);
	if (map->north != NULL)
		free(map->north);
	if (map->east != NULL)
		free(map->east);
	if (map->south != NULL)
		free(map->south);
	if (map->floor != NULL)
		free(map->floor);
	if (map->west != NULL)
		free(map->west);
}

void	free_malloc(char **stockf, int l)
{
	int	y;

	y = 0;
	if (stockf == NULL)
		return ;
	while (y < l)
	{
		free (stockf[y]);
		y++;
	}
	free (stockf);
}

void	print_err(char *str, t_map *map)
{
	if (map->valid_content == false)
		return ;
	printf("%s\n", str);
	map->valid_content = false;
}
