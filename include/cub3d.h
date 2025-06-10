/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:08:35 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/09 16:50:25 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SUCCESS 0
# define FAILURE 1

// # define WIN_WIDTH 320
// # define WIN_HEIGHT 200

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

// # define WIN_WIDTH 1024
// # define WIN_HEIGHT 768

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

typedef struct	s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_map
{
	char	**content;
	int		sizeL;
	bool	valid_content;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor; //floor bacic
	long	floor_color; //floor convert
	char	*ceiling; //ceiling basic
	long	ceiling_color; //ceiling convert
	char	initial_position; //Where he is looking at N : North S : South E : East W:West
	int		initial_posX;
	int		initial_posY;
	int		index;
	int		size;
	double	step;
	double	pos;
	int		x;
	int		y;
	int		map_width;
	int		i;
}				t_map;

typedef struct	s_ray
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

typedef struct	s_player
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

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_heght;
	t_map		mapinfo;
	char		**map;
	t_ray		ray;
	t_player	player;
	int			**textures;
	int			**texture_pixels;
}				t_game;

/* init_data.c*/
void	init_img_zero(t_img *img);
void	init_ray(t_ray *ray);
void	init_player(t_player *player, t_map *map);
void	init_map(t_map *mapinfo);
void	init_game(t_game *game);

/* raycasting.c*/
int		raycasting(t_player *player, t_game *game);
void	render_raycast(t_game *game);


/*   free_game.c   */
void	free_malloc(char **stockf, int l);
void	free_tab(void **tab);
void	free_map(t_map *map);
void	free_game(t_game *game);

/*   exit.c   */
int		exit_game(t_game *game);
void	clean_exit(t_game *game, int code);

/*   init_textures.c   */
void	update_texture_pixels(t_game *game, t_map *map, t_ray *ray, int x);
void	init_texture_pixels(t_game *game);

/*   render_texture.c   */
void	init_texture_image(t_game *game, t_img *img, char *path);
void	init_textutes(t_game *game);

/*   render_frame.c   */
void	render_frame(t_game *game);

/*   render.c   */
int		validate_move(t_game *game, double new_x, double new_y);
int		render(t_game *game);

/*   player_move.c   */
int	player_move(t_game *game);

/*typedef struct s_map
{
	char	**content; //whole map
	int		sizeL; //nbline
	bool	valid_content; //verif if content respect the rules
	char	*north; //link for north texture
	char	*south; //link for south texture
	char	*east; //link for east texture
	char	*west; //link for west  texture
	char	*floor; //floor bacic
	int		floor_color; //floor convert
	char	*ceiling; //ceiling basic
	int		ceiling_color; //ceiling convert
	char	initial_position; //Where he is looking at N : North S : South E : East W:West
	int		i;

}				t_map;*/


void	init_content(t_map *map, int fd);
char	*full_line(int fd);
size_t	ft_strlen(const char *theString);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *string, int searchedChar );
char	*ft_strjoin(char const *s1, char const *s2);
char	*stock_texture(char *stock, int i, t_map *map);
void	search_for_texture(t_map *map, char *stock);
void	search_for_east(t_map *map, char *stock);
void	search_for_west(t_map *map, char *stock);
void	search_for_south(t_map *map, char *stock);
void	search_for_north(t_map *map, char *stock);
char	*stock_texture(char *stock, int i, t_map *map);
int		verif_floor_ceiling(char *color);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src );
void	search_for_map(t_map *map, char *stock);
void	verif_map(t_map *map);
void	wall_around(t_map *map, int y, int i);


void	init_player_direction(t_player *player, t_map *map);


void	init_content(t_map *map, int fd);
char	*full_line(int fd);
size_t	ft_strlen(const char *theString);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *string, int searchedChar );
char	*ft_strjoin(char const *s1, char const *s2);
char	*stock_texture(char *stock, int i, t_map *map);
void	search_for_texture(t_map *map, char *stock);
void	search_for_east(t_map *map, char *stock);
void	search_for_west(t_map *map, char *stock);
void	search_for_south(t_map *map, char *stock);
void	search_for_north(t_map *map, char *stock);
int		verif_floor_ceiling(char *color);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src );
void	search_for_map(t_map *map, char *stock);
void	verif_map(t_map *map);
void	wall_around(t_map *map, int y, int i);
void	free_malloc(char **stockf, int l);
//void	free_all(t_map *map);
void	print_err(char *str, t_map *map);
void	alloc_line(t_map *map, char *stock);
int		get_content(char c, t_map *map, int l, int i);
void	empty_line(t_map *map, int y, int i);
int		ft_isnumeric(char *str);
int		ft_isdigit(int c);

/*   DELETE THIS   */
void	print_game_state(t_game *game);
void	debug_display_data( t_game *data);

#endif
