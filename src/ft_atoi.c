/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:18:14 by jkerthe           #+#    #+#             */
/*   Updated: 2023/10/25 13:30:13 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	neg;

	res = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}
/*
#include <stdio.h>
int    main(int argc, char *argv[])
{
    if (1 < argc)
    {
        printf("ft_atoi = '%d'\n", ft_atoi(argv[1]));
        printf("   atoi = '%d'\n", atoi(argv[1]));
    }
    else
        printf("required 'nb'\n");
}
*/
