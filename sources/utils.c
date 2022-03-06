/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:29:41 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/06 16:07:35 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	destroy_threads(t_config *config)
{
	int	i;

	i = config->n_philos;
	while (i)
	{
		pthread_mutex_destroy(&config->fork[i]);
		i--;
	}
	pthread_mutex_destroy(config->print);
	return (0);
}

int	free_all(t_config *config)
{
	free(config->philo);
	free(config->fork);
	free(config->print);
	destroy_threads(config);
	return (0);
}

void	print_infos(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->n_philos)
	{
		printf("id = %d\n \
		rfork = %d\n \
		lfork = %d\n \
		lst_meal = %ld\n \
		ate = %d\n",
			config->philo[i].id,
			config->philo[i].rfork,
			config->philo[i].lfork,
			config->philo[i].lst_meal,
			config->philo[i].ate);
		i++;
	}
}

int	is_numeric_chars(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}
