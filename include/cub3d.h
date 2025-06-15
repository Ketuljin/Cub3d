/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:08:35 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/15 14:12:31 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SUCCESS 0
# define FAILURE 1

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define BUFFER_SIZE 15
# define TEX_SIZE 64
# define MOVESPEED 0.025
# define ROTSPEED 0.025

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

enum e_texture_indexes
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_map
{
	char	**content;
	int		size_l;
	bool	valid_content;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	long	floor_color;
	char	*ceiling;
	long	ceiling_color;
	char	initial_position;
	int		initial_pos_x;
	int		initial_pos_y;
	int		index;
	int		size;
	double	step;
	double	pos;
	int		x;
	int		y;
	int		map_width;
	int		i;
	int		j;
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
	t_ray		ray;
	t_player	player;
	int			**textures;
	int			**texture_pixels;
}				t_game;

/* alloc_line.c */
void	alloc_line(t_map *map, char *stock);

/* alloc_map.c */
void	search_for_start(t_map *map, char *stock);
int		count_line(t_map *map, char *stock);
void	create_map(t_map *map, char *stock);
void	search_for_map(t_map *map, char *stock);

/* errors.c   */
void	print_err(char *str, t_map *map);

/* exit.c   */
int		exit_game(t_game *game);
void	clean_exit(t_game *game, int code);

/* free_game.c   */
void	free_tab(void **tab);
void	free_map(t_map *map);
void	free_game(t_game *game);

/* ft_atoi.c */
int		ft_atoi(const char *str);

/*   ft_isnumeric.c */
int		ft_isnumeric(char *str);

/*   ft_split.c */
char	**ft_split(char const *s, char c);

/*   ft_strdup.c */
char	*ft_strdup(const char *src );

/*   ft_substr.c */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*   full_line.c */
char	*full_line(int fd);

/*   get_next_line_utils.c */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar);
void	*ft_calloc(size_t elementCount, size_t elementSize);
size_t	ft_strlen(const char *theString);

/*   get_texture_utils.c */
void	search_for_north(t_map *map, char *stock);
void	search_for_south(t_map *map, char *stock);
void	search_for_west(t_map *map, char *stock);
void	search_for_east(t_map *map, char *stock);

/*   get_texture.c */
void	search_for_texture(t_map *map, char *stock);

/*   init_content.c */
void	init_content(t_map *map, int fd);

/* init_data.c */
void	init_map(t_map *map);
void	init_img_zero(t_img *img);
void	init_ray(t_ray *ray);
void	init_player(t_player *player, t_map *map);
void	init_game(t_game *game);

/* init_mlx.c */
void	listener(t_game *game);
int		init_mlx(t_game *game);

/*   init_player_dir.c */
void	init_player_direction(t_player *player, t_map *map);

/*   init_textures.c   */
void	update_texture_pixels(t_game *game, t_map *map, t_ray *ray, int x);
void	init_texture_pixels(t_game *game);

/*   player_move.c   */
int		player_move(t_game *game);

/*   player_rotate.c */
int		player_rotate(t_game *game, double rotdir);

/* raycasting.c */
int		raycasting(t_player *player, t_game *game);

/*   render_frame.c */
void	render_frame(t_game *game);
void	render_raycast(t_game *game);

/*   render_texture.c   */
void	init_textutes(t_game *game);

/*   render.c   */
int		validate_move(t_game *game, double new_x, double new_y);
int		render(t_game *game);

/*   stock_texture.c */
int		skip_spaces_newlines(char *stock, int i);
char	*stock_texture(char *stock, int i, t_map *map);

/*   verif_file.c */
int		check_error(t_map *map, char *stock);
void	verif_file(t_map *map);

/*   verif_map_utils.c */
void	empty_line(t_map *map);
int		get_content(char c, t_map *map, int l, int i);

/*   verif_map.c */
void	verif_map(t_map *map);

/*   wall_around.c */
void	wall_around(t_map *map, int y, int i);

/*   DELETE THIS   */
void	print_game_state(t_game *game);
void	debug_display_data( t_game *data);

char	*ft_strrchr(const char *string, int s);
char	value_pos(t_map *map, int y, int i);
void	free_malloc(char **stockf, int l);
void	debug_display_mapinfo( t_game *data);
char	*stock_color(char *stock, int i, t_map *map);
#endif
