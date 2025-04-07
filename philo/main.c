/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:15:12 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/07 20:09:24 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int start_simulation(t_data *data, t_philo *philos)
{
	int i;

	data->start_time = get_time_ms();
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]) != 0)
			return (error_msg("Failed to create thread\n"));
		i++;
	}
	return (0);
}

static void wait_for_threads(t_data *data, t_philo *philos)
{
	int i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data data;
	t_philo *philos;

	if (parse_args(argc, argv, &data) != 0)
		return (1);
	if (init_all(&data, &philos) != 0)
		return (1);
	if (start_simulation(&data, philos) != 0)
		return (1);
	wait_for_threads(&data, philos);
	cleanup(&data, philos);
	return (0);
}
