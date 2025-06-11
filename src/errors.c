/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:51:55 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/11 12:32:15 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_err(char *str, t_map *map)
{
	if (map->valid_content == false)
		return ;
	printf("%s\n", str);
	map->valid_content = false;
}
