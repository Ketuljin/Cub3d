/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:30:29 by jkerthe           #+#    #+#             */
/*   Updated: 2025/05/20 14:51:59 by jkerthe          ###   ########.fr       */
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


void	init_content(t_map *map, int fd);
char	*full_line(int fd);
size_t	ft_strlen(const char *theString);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *string, int searchedChar );
char	*ft_strjoin(char const *s1, char const *s2);
char	*stock_texture(char *stock, int i);
void	search_for_texture(t_map *map, char *stock);


#endif