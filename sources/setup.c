/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:34 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/05 18:57:16 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	invalid_args(int argc, char **argv)
{
	int	count_args;

	count_args = 1;
	if (argc < 5 || argc > 6)
		return (print_errors(ERR_NUMBERS_ARGS));
	while (argv[count_args])
	{
		if (is_numeric_chars(argv[count_args]))
			return (print_errors(ERR_INVALID_ARGS));
		count_args++;
	}
	return (0);
}

int	get_info(t_config *config, char **argv)
{
	int	i;

	i = 0;
	config->n_philos = ft_atoi(argv[++i]);
	config->t_die = ft_atoi(argv[++i]);
	config->t_eat = ft_atoi(argv[++i]);
	config->t_sleep = ft_atoi(argv[++i]);
	if (argv[++i])
	{
		config->times_must_eat = ft_atoi(argv[i]);
	}
	return (0);
}

int	invalid_simulation(t_config *config, char **argv)
{
	if (config->n_philos < 1)
		return (print_errors(ERR_NUMBER_PHILOS));
	if (config->t_die == 0 || config->t_eat == 0
		|| config->t_sleep == 0)
		return (print_errors(ERR_INVALID_VALUE));
	if (argv[5] && config->times_must_eat == 0)
		return (print_errors(ERR_INVALID_VALUE));
	return (0);
}

int	create_philos(t_config *config)
{
	int	i;

	i = 0;
	config->philo = malloc(sizeof(t_philo) * config->n_philos);
	config->fork = malloc(sizeof(pthread_mutex_t) * config->n_philos);
	while (i < config->n_philos)
	{
		config->philo[i].id = i + 1;
		config->philo[i].ate = 0;
		config->philo[i].rfork = i;
		config->philo[i].lfork = i + 1;
		config->philo[i].lst_meal = get_now();
		config->philo[i].config = config;
		pthread_mutex_init(&config->fork[i], NULL);
		i++;
	}
	config->philo[i - 1].lfork = 0;
	return (0);
}

int	setup(int argc, char **argv, t_config *config)
{
	if (invalid_args(argc, argv))
		return (1);
	if (get_info(config, argv))
		return (2);
	if (invalid_simulation(config, argv))
		return (3);
	create_philos(config);
	if (!config->fork || !config->philo)
		return (free_all(config));
	return (0);
}
