/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:48:52 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/01 18:32:29 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	should_stop(t_config *config)
{
	int	i;
	int	have_ate_enough;

	i = 0;
	have_ate_enough = 0;
	while (i < config->n_philos)
	{
		if (get_now() - config->philo[i].lst_meal > config->t_die)
		{
			print_status(get_now(), &config->philo[i], "died");
			return (1);
		}
		if (config->times_must_eat
			&& config->philo[i].t_ate >= config->times_must_eat)
			have_ate_enough++;
		i++;
	}
	if (config->times_must_eat
		&& have_ate_enough == config->n_philos)
		return (2);
	return (0);
}

void	*monitor_routine(void *sett)
{
	t_config	*config;

	config = sett;
	while (!config->should_stop)
	{
		config->should_stop = should_stop(config);
		usleep(1000);
	}
	return (NULL);
}
