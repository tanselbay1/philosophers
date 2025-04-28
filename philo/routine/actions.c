/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbay1 <tanselbay1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:14:48 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/28 17:19:05 by tanselbay1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// int take_forks(t_philo *philo)
// {
// 	if (check_death(philo))
// 		return (1);
// 	pthread_mutex_lock(&philo->data->forks_lock);
// 	if (pthread_mutex_lock(philo->left_fork) != 0)
// 	{
// 		pthread_mutex_unlock(&philo->data->forks_lock);
// 		return (1);
// 	}
// 	print_status(philo, "has taken a fork");
// 	if (pthread_mutex_lock(philo->right_fork) != 0)
// 	{
// 		pthread_mutex_unlock(philo->left_fork);
// 		pthread_mutex_unlock(&philo->data->forks_lock);
// 		return (1);
// 	}
// 	print_status(philo, "has taken a fork");
// 	pthread_mutex_unlock(&philo->data->forks_lock);
// 	return (0);
// }

int take_forks(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	if (philo->id % 2 == 0) // even ID
	{
		pthread_mutex_lock(philo->left_fork);
		philo->has_left_fork = 1;
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		philo->has_right_fork = 1;
		print_status(philo, "has taken a fork");
	}
	else // odd ID
	{
		pthread_mutex_lock(philo->right_fork);
		philo->has_right_fork = 1;
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		philo->has_left_fork = 1;
		print_status(philo, "has taken a fork");
	}
	return (0);
}

int eat(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	pthread_mutex_lock(&philo->data->death);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->data->death);
	print_status(philo, "is eating");
	smart_sleep(philo->data->time_to_eat, philo);
	philo->meals_eaten++;
	if (philo->data->max_meals > 0 && philo->meals_eaten == philo->data->max_meals)
	{
		pthread_mutex_lock(&philo->data->death);
		philo->data->full_count++;
		pthread_mutex_unlock(&philo->data->death);
		printf("Philosopher %d has finished eating %d meals\n", philo->id, philo->meals_eaten); // Debugging log
	}
	pthread_mutex_unlock(philo->left_fork);
	philo->has_left_fork = 0;
	pthread_mutex_unlock(philo->right_fork);
	philo->has_right_fork = 0;
	return (0);
}

int sleep_and_think(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	print_status(philo, "is sleeping");
	smart_sleep(philo->data->time_to_sleep, philo);
	if (check_death(philo))
		return (1);
	print_status(philo, "is thinking");
	return (0);
}
