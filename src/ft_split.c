/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:26:05 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/06 17:34:25 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	countword(char const *s, char c)
{
	size_t			taillel;
	int				skip;

	taillel = 0;
	skip = 1;
	while (*s)
	{
		if (*s != c && skip)
		{
			skip = 0;
			taillel++;
		}
		else if (*s == c)
			skip = 1;
		s++;
	}
	return (taillel);
}

static void	creatab(char **split, char const *s, char c, size_t tw)
{
	char	*ptr_c;

	while (*s && *s == c)
		s++;
	while (tw--)
	{
		ptr_c = ft_strchr(s, c);
		if (ptr_c != NULL)
		{
			*split = ft_substr(s, 0, ptr_c - s);
			while (*ptr_c && *ptr_c == c)
				ptr_c++;
			s = ptr_c;
		}
		else
			*split = ft_substr(s, 0, ft_strlen(s) + 1);
		split++;
	}
	*split = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t		tw;
	char		**split;

	if (s == NULL)
		return (NULL);
	tw = countword(s, c);
	split = (char **)malloc (sizeof (char *) * (tw +1));
	if (split == NULL)
		return (NULL);
	creatab (split, s, c, tw);
	return (split);
}
/*
int main(void) {
    int i = 0;
    int j = 0;
    char *str = "LaZmaison";
    char **split = ft_split(str, ' ');

    while (split[j] != NULL) {
        i = 0;
        while (split[j][i] != '\0') {
            write(1, &split[j][i], 1);
            i++;
        }
        j++;
    }

    //free_split(split); // Free allocated memory
    return 0;
}
*/
