/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:08:35 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/26 12:38:06 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_h
# define CUB3D_H

# define SUCCESS 0
# define FAILURE 1

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_map
{
	char	**content;
	int		sizeL;
	bool	valid_content;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceiling;
}				t_map;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_heght;
	t_map		mapinfo;
	char		**map;
	t_ray		ray;
	t_player	player;
}				t_game;

/* init_data.c*/
void	init_ray(t_ray *ray);
void	init_player(t_player *player);
void	init_map(t_map *mapinfo);
void	init_game(t_game *game);

#endif
