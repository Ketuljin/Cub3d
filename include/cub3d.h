/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:08:35 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/20 12:42:28 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_h
# define CUB3D_H

# define SUCCESS 0
# define FAILURE 1

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
}				t_game;




#endif
