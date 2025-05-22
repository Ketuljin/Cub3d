/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:08:35 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/22 13:36:23 by rureshet         ###   ########.fr       */
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

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_heght;
	t_map		*map;
	t_player	*player;
}				t_game;

#endif
