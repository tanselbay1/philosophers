/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:38:07 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/14 13:54:24 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int init_mutexes(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->death, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->forks_lock, NULL) != 0)
		return (1);
	return (0);
}

static void init_philos(t_data *data, t_philo *philos)
{
	int i;

	i = 0;
	while (i < data->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_time_ms();
		philos[i].data = data;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->n_philos];
		i++;
	}
}

int init_all(t_data *data, t_philo **philos_out)
{
	data->dead = 0;
	data->full_count = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (error_msg("Failed to allocate forks\n"));
	*philos_out = malloc(sizeof(t_philo) * data->n_philos);
	if (!*philos_out)
		return (error_msg("Failed to allocate philos\n"));
	if (init_mutexes(data) != 0)
		return (error_msg("Failed to initialize mutexes\n"));
	init_philos(data, *philos_out);
	return (0);
}
