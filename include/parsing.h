/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:30:29 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/22 14:12:13 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

#define BUFFER_SIZE 15

typedef struct s_map
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
	int		initial_posX;
	int		initial_posY;
	int		i;

}				t_map;	


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


#endif