/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:00:38 by elima-me          #+#    #+#             */
/*   Updated: 2022/02/28 20:08:24 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	eat(t_philo *philo)
{
	printf("retorno mutex: %d\nphilo: %d\n",
		pthread_mutex_lock(&philo->config->fork[philo->rfork]), philo->id);
	printf("%lld \t %d has taken fork\n",
		(get_now() - philo->config->sim_start), philo->id);
	printf("retorno mutex: %d\nphilo: %d\n",
		pthread_mutex_lock(&philo->config->fork[philo->lfork]), philo->id);
	printf("%lld \t %d has taken fork\n",
		(get_now() - philo->config->sim_start), philo->id);
	printf("%lld \t %d is eating\n",
		(get_now() - philo->config->sim_start), philo->id);
	pthread_mutex_unlock(&philo->config->fork[philo->rfork]);
	pthread_mutex_unlock(&philo->config->fork[philo->lfork]);
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = philo;
	if (p->id % 2 == 0)
		usleep(1600);
	eat(p);
	return (0);
}

int	start_banquet(t_config *config)
{
	int	i;

	i = 0;
	config->sim_start = get_now();
	while (i < config->n_philos)
	{
		pthread_create(&config->philo[i].thread, NULL,
			&routine, &config->philo[i]);
		i++;
	}
	i = 0;
	while (i < config->n_philos)
	{
		pthread_join(config->philo[i].thread, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_config	config;

	memset(&config, '\0', sizeof(t_config));
	if (setup(argc, argv, &config))
		return (1);
	start_banquet(&config);
	free_all(&config);
	return (0);
}
