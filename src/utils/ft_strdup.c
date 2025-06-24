/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:27:52 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/24 14:26:34 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strdup(const char *src )
{
	char			*dest;
	size_t			i;

	i = 0;
	dest = (char *) malloc(sizeof(const char) * ft_strlen(src) +1);
	if (dest == NULL)
		return (NULL);
	else
	{
		dest[ft_strlen(src)] = '\0';
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
