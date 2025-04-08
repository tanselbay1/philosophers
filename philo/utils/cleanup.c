#include "../philo.h"

void cleanup(t_data *data, t_philo *philos)
{
	int i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->forks_lock);
	free(data->forks);
	free(philos);
}
