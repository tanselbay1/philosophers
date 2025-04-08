/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:59:57 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/07 20:58:04 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_data
{
	int n_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int max_meals;
	int full_count;
	int dead;
	long start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
	pthread_mutex_t death;
	pthread_mutex_t forks_lock;
} t_data;

typedef struct s_philo
{
	int id;
	int meals_eaten;
	long last_meal;
	pthread_t thread;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	t_data *data;
} t_philo;

// Function prototypes
int ft_atoi(const char *str);
int parse_args(int argc, char **argv, t_data *data);
int init_all(t_data *data, t_philo **philos_out);
int check_death(t_philo *philo);
void print_status(t_philo *philo, char *msg);
void smart_sleep(long ms, t_philo *philo);
int take_forks(t_philo *philo);
int eat(t_philo *philo);
int sleep_and_think(t_philo *philo);
void *philo_routine(void *arg);
void *monitor(void *arg);
long get_time_ms(void);
int error_msg(const char *msg);
void cleanup(t_data *data, t_philo *philos);

#endif