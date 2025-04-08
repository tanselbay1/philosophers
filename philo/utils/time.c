/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:49:58 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/07 20:58:13 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void smart_sleep(long ms, t_philo *philo)
{
	long start;

	start = get_time_ms();
	while ((get_time_ms() - start) < ms)
	{
		if (check_death(philo))
			break;
		usleep(500);
	}
}

long get_time_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}