/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbayraktaroglu <tanselbayraktarogl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:23:26 by tanselbayra       #+#    #+#             */
/*   Updated: 2025/04/11 13:56:20 by tanselbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int is_number(char *str)
{
	int i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int fill_data(t_data *data, char **argv)
{
	data->n_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->max_meals = -1;
	if (argv[5])
		data->max_meals = ft_atoi(argv[5]);
	if (data->n_philos < 1 || data->time_to_die < 0 || data->time_to_eat < 0 || data->time_to_sleep < 0 || (argv[5] && data->max_meals <= 0))
		return (1);
	return (0);
}

int parse_args(int argc, char **argv, t_data *data)
{
	int i;

	if (argc != 5 && argc != 6)
		return (error_msg("Usage: ./philo n t_die t_eat t_sleep [max_meals]\n"));
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (error_msg("All arguments must be positive integers\n"));
		i++;
	}
	if (fill_data(data, argv))
		return (error_msg("Invalid argument values\n"));
	return (0);
}
