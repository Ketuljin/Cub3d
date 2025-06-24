/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rureshet <rureshet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:37:16 by jkerthe           #+#    #+#             */
/*   Updated: 2025/06/12 17:11:44 by rureshet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_isdigit(int c)
{
	if ((c <= 57 && c >= 48))
	{
		return (1);
	}
	return (0);
}

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\t' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
