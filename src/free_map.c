/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:51:55 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/06 17:34:25 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	free_all(t_map *map)
// {
// 	free(map->ceiling);
// 	free(map->north);
// 	free(map->east);
// 	free(map->south);
// 	free(map->floor);
// 	free(map->west);
// }

void	free_malloc(char **stockf, int l)
{
	int	y;

	y = 0;
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
