/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_banquet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:25:47 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/02 14:09:40 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->config->fork[philo->rfork]);
	if (philo->config->should_stop)
	{
		pthread_mutex_unlock(&philo->config->fork[philo->rfork]);
		return ;
	}
	print_status(get_now(), philo, "has taken a fork");

	pthread_mutex_lock(&philo->config->fork[philo->lfork]);
	if (philo->config->should_stop)
	{
		pthread_mutex_unlock(&philo->config->fork[philo->rfork]);
		pthread_mutex_unlock(&philo->config->fork[philo->lfork]);
		return ;
	}
	print_status(get_now(), philo, "has taken a fork");
	print_status(get_now(), philo, "is eating");
	philo->lst_meal = get_now();
	philo->t_ate += 1;
	usleep(philo->config->t_eat * 1000);
	pthread_mutex_unlock(&philo->config->fork[philo->rfork]);
	pthread_mutex_unlock(&philo->config->fork[philo->lfork]);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = philo;
	if (p->id % 2 == 0)
		usleep(1600);
	while (!p->config->should_stop)
	{
		eat(p);
		if(p->config->should_stop)
			return (0);
		print_status(get_now(), p, "is sleeping");
		usleep(p->config->t_sleep * 1000);
		if (p->config->should_stop)
			return (0);
		print_status(get_now(), p, "is thinking");
	}
	return (0);
}

int	start_banquet(t_config *config)
{
	int	i;

	i = -1;
	config->sim_start = get_now();
	while (++i < config->n_philos)
	{
		pthread_create(&config->philo[i].thread, NULL,
			&routine, &config->philo[i]);
	}
	pthread_create(&config->monitor, NULL, &monitor_routine, config);
	i = -1;
	while (++i < config->n_philos)
		pthread_join(config->philo[i].thread, NULL);
	pthread_join(config->monitor, NULL);
	return (0);
}
