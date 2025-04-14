/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:57:09 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/14 14:23:49 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int philo_died(t_philo *philo)
{
    long now;
    long last_meal;

    now = get_time_ms();
    pthread_mutex_lock(&philo->data->death);
    last_meal = philo->last_meal;
    pthread_mutex_unlock(&philo->data->death);
    if (now - last_meal > philo->data->time_to_die)
    {
        philo->data->dead = 1;
        pthread_mutex_unlock(&philo->data->death);
        pthread_mutex_lock(&philo->data->print);
        printf("%ld %d died\n", now - philo->data->start_time, philo->id);
        pthread_mutex_unlock(&philo->data->print);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->death);
    return (0);
}

static int all_full(t_data *data)
{
    int done;

    done = 0;
    if (data->max_meals > 0)
    {
        pthread_mutex_lock(&data->death);
        if (data->full_count >= data->n_philos)
            done = 1;
        pthread_mutex_unlock(&data->death);
    }
    return (done);
}

void *monitor(void *arg)
{
    t_philo *philos;
    t_data *data;
    int i;

    i = 0;
    philos = (t_philo *)arg;
    data = philos[i].data;
    while (1)
    {
        i = 0;
        while (i < data->n_philos)
        {
            if (philo_died(&philos[i]))
                return (NULL);
            i++;
        }
        if (all_full(data))
        {
            pthread_mutex_lock(&data->death);
            data->dead = 1;
            pthread_mutex_unlock(&data->death);
            printf("All philosophers have finished their meals. Simulation ending.\n"); // Debugging log
            return (NULL);
        }
        usleep(1000);
    }
    return (NULL);
}
