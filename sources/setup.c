/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:34 by elima-me          #+#    #+#             */
/*   Updated: 2022/02/12 14:20:52 by elima-me         ###   ########.fr       */
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

int	get_info(t_infoPhilos *info_philos, char **argv)
{
	int	i;

	i = 0;
	ft_bzero(info_philos, sizeof(t_infoPhilos));
	info_philos->n_philos = ft_atoi(argv[++i]);
	info_philos->time_to_die = ft_atoi(argv[++i]);
	info_philos->time_to_eat = ft_atoi(argv[++i]);
	info_philos->time_to_sleep = ft_atoi(argv[++i]);
	if (argv[++i])
	{
		info_philos->times_must_eat = ft_atoi(argv[i]);
	}
	return (0);
}

int	game_validator(t_infoPhilos *info_philos, char **argv)
{
	if (info_philos->n_philos < 1)
		return (print_errors(ERR_NUMBER_PHILOS));
	if (info_philos->time_to_die == 0)
		return (print_errors(ERR_INVALID_VALUE));
	if (info_philos->time_to_eat == 0)
		return (print_errors(ERR_INVALID_VALUE));
	if (info_philos->time_to_sleep == 0)
		return (print_errors(ERR_INVALID_VALUE));
	if (argv[5] && info_philos->times_must_eat == 0)
		return (print_errors(ERR_INVALID_VALUE));
	return (0);
}

int	setup(int argc, char **argv, t_infoPhilos *info_philos)
{
	if (invalid_args(argc, argv))
		return (1);
	if (get_info(info_philos, argv))
		return (2);
	if (game_validator(info_philos, argv))
		return (3);
	return (0);
}
