/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_banquet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:25:47 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/05 18:38:47 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	unlock_mutex(t_philo *philo)
{
	if (philo->config->should_stop)
	{
		pthread_mutex_unlock(&philo->config->fork[philo->rfork]);
		pthread_mutex_unlock(&philo->config->fork[philo->lfork]);
		return (1);
	}
	return (0);
}

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
	if (unlock_mutex(philo))
		return ;
	print_status(get_now(), philo, "has taken a fork");
	philo->lst_meal = get_now();
	print_status(get_now(), philo, "is eating");
	philo->ate++;
	usleep(philo->config->t_eat * 1000);
	if (unlock_mutex(philo))
		return ;
	print_status(get_now(), philo, "is sleeping");
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
		if (p->config->should_stop)
			break ;
		usleep(p->config->t_sleep * 1000);
		if (p->config->should_stop)
			break ;
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
