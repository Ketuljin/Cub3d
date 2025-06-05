/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:29:42 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/05 12:42:43 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	*ft_strrchr(const char *string, int s)
{
	size_t		i;
	char		*t;

	t = NULL;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)s)
			t = ((char *)&string[i]);
		i++;
	}
	if (string[i] == (char)s)
		t = ((char *)&string[i]);
	return (t);
}

int	check_name(char *argv)
{
	char	*cub;
	char	*tab;
	int		i;
	int		fd;

	i = 0;
	cub = ".cub";
	tab = ft_strrchr(argv, '.');
	if (tab == NULL)
		return (0);
	while (cub[i])
	{
		if (tab[i] != cub[i])
			return (0);
		i++;
	}
	if (tab[i] != cub[i])
		return (0);
	fd = open (argv, O_RDONLY);
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = 0;
	if (argc != 2)
	{
		printf("Error/ You need one argument: a file.cub\n");
		return (1);
	}
	else
	{
		fd = check_name(argv[1]);
		if (fd <= 0)
			return (1);
		init_content(&map, fd);
		if (map.valid_content == false)
		{
			free_all(&map);
			free_malloc(map.content, map.sizel);
			return (1);
		}
	}
	free_all(&map);
	free_malloc(map.content, map.sizel);
}
