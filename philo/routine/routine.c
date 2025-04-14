/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:56:08 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/14 14:00:37 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int check_death(t_philo *philo)
{
	int ret;

	if (!philo || !philo->data) // Add null checks
		return (1);
	pthread_mutex_lock(&philo->data->death);
	ret = philo->data->dead;
	pthread_mutex_unlock(&philo->data->death);
	return (ret);
}

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (!philo || !philo->data) // Add null checks
	{
		printf("Error: Philosopher or data is null\n");
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);																	  // Slight delay to reduce contention
	printf("Philosopher %d starting with last_meal: %ld\n", philo->id, philo->last_meal); // Debugging log
	while (!check_death(philo))
	{
		if (take_forks(philo) != 0)
			break;
		if (eat(philo) != 0)
			break;
		if (sleep_and_think(philo) != 0)
			break;
	}
	return (NULL);
}