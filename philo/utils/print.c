/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:17:27 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/07 21:05:41 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void print_status(t_philo *philo, char *msg)
{
   long timestamp;

   timestamp = get_time_ms() - philo->data->start_time;
   pthread_mutex_lock(&philo->data->print);
   if (!check_death(philo))
      printf("%ld %d %s\n", timestamp, philo->id, msg);
   pthread_mutex_unlock(&philo->data->print);
}
