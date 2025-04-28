/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:56:08 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/28 19:05:02 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_death(t_philo *philo)
{
	int	ret;

	if (!philo || !philo->data)
		return (1);
	pthread_mutex_lock(&philo->data->death);
	ret = philo->data->dead;
	pthread_mutex_unlock(&philo->data->death);
	return (ret);
}

void	*one_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	smart_sleep(philo->data->time_to_die, philo);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo || !philo->data)
		return (NULL);
	if (philo->data->n_philos == 1)
		return (one_philo_routine(philo));
	if (philo->id % 2 == 0)
		usleep(200);
	while (!check_death(philo))
	{
		if (take_forks(philo) != 0)
			break ;
		if (eat(philo) != 0)
			break ;
		if (sleep_and_think(philo) != 0)
			break ;
	}
	if (philo->has_left_fork)
		pthread_mutex_unlock(philo->left_fork);
	if (philo->has_right_fork)
		pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}
// printf("Error: Philosopher or data is null\n");