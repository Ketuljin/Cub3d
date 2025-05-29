/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:29:42 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/29 19:17:39 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/cub3d.h"

int	key_press_handle(int key, t_game *game)
{
	(void)game;
	if (key == XK_Left)
		printf("<--\n");
	else if (key == XK_Right)
		printf("-->\n");
	else if (key == XK_w)
		printf("W\n");
	else if (key == XK_s)
		printf("S\n");
	else if (key == XK_a)
		printf("A\n");
	else if (key == XK_d)
		printf("D\n");
	return(0);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return(FAILURE);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		return(FAILURE);
	mlx_hook(game->win, 17, 0, exit_game, &game);
	mlx_hook(game->win, 2, 1L<<0, key_press_handle, game);

	return(SUCCESS);
}

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
	int			fd;
	t_game		game;

	fd = 0;
	if (argc != 2)
	{
		printf("You need one argument: a file.cub");
		return (1);
	}
	else
	{
		fd = check_name(argv[1]);
		if (fd <= 0)
		{
			printf("ERROR\n Wrong name");
			return (1);
		}
		init_content(&game.mapinfo, fd);
	}
	init_game(&game);
	init_player_direction(&game.player, &game.mapinfo);
	if(init_mlx(&game) == FAILURE)
		return (FAILURE);
	render_raycast(&game);
	print_game_state(&game); // DELETE THIS - NEED FOR TEST
	mlx_loop(game.mlx);
	return(SUCCESS);
}
