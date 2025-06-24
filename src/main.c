/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:29:42 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/24 14:44:28 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strrchr(const char *string, int s)
{
	size_t	i;
	char	*t;

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

int	parsing(int argc, char **argv, t_game *game)
{
	int	fd;

	fd = 0;
	if (argc != 2)
		return (printf("Error/ You need one argument: a file.cub\n"), 1);
	else
	{
		fd = check_name(argv[1]);
		if (fd <= 0)
			return (printf("You have to give a file.cub\n"), 1);
		init_game(game);
		init_content(&game->mapinfo, fd);
		if (game->mapinfo.valid_content == false)
		{
			free_game(game);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (parsing(argc, argv, &game) == 1)
		return (FAILURE);
	init_game(&game);
	init_player_direction(&game.player, &game.mapinfo);
	if (init_mlx(&game) == FAILURE)
		return (FAILURE);
	init_textutes(&game);
	render_raycast(&game);
	listener(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (SUCCESS);
}
