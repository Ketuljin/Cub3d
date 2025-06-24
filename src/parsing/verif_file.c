/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:35:19 by rureshet          #+#    #+#             */
/*   Updated: 2025/06/24 14:40:58 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_error(t_map *map, char *stock)
{
	if (map->floor == NULL && map->ceiling == NULL && map->north == NULL
		&& map->south == NULL && map->east == NULL && map->west == NULL
		&& stock[0] == '\0')
		return (print_err("ERROR/ Empty file\n", map), 1);
	if (map->north == NULL)
		return (print_err("ERROR/ North missing\n", map), 1);
	if (map->south == NULL)
		return (print_err("ERROR/ South missing\n", map), 1);
	if (map->west == NULL)
		return (print_err("ERROR/ West missing\n", map), 1);
	if (map->east == NULL)
		return (print_err("ERROR/ East missing\n", map), 1);
	if (map->floor == NULL)
		return (print_err("ERROR/ Floor missing\n", map), 1);
	if (map->ceiling == NULL)
		return (print_err("ERROR/ Ceiling missing\n", map), 1);
	if (stock[0] == '\0')
		return (print_err("ERROR/ There is no map\n", map), 1);
	return (0);
}

static int	extention_texture(char	*str, t_map *map)
{
	char	*xpm;
	char	*ext;

	xpm = ".xpm";
	ext = ft_strrchr(str, '.');
	if (ext == NULL)
	{
		print_err("ERROR/ Your texture need to be .xpm", map);
		return (0);
	}
	if (strcmp(ext, xpm) == 0)
		return (1);
	print_err("ERROR/ Your texture need to be .xpm", map);
	return (0);
}

void	verif_file(t_map *map)
{
	if (map->valid_content == false)
		return ;
	if (!extention_texture(map->north, map) || access(map->north, R_OK) != 0)
		print_err("Error/ North: No such file or directory\n", map);
	if (!extention_texture(map->south, map) || access(map->south, R_OK) != 0)
		print_err("Error/ South: No such file or directory\n", map);
	if (!extention_texture(map->east, map) || access(map->east, R_OK) != 0)
		print_err("Error/ East: No such file or directory\n", map);
	if (!extention_texture(map->west, map) || access(map->west, R_OK) != 0)
		print_err("Error/ West: No such file or directory\n", map);
}
