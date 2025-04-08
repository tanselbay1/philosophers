/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:20:24 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/07 16:34:29 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_atoi(const char *str)
{
	long result;
	int i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647)
			return (-1);
		i++;
	}
	return ((int)result);
}
