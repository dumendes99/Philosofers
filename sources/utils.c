/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:29:41 by elima-me          #+#    #+#             */
/*   Updated: 2022/02/28 19:39:58 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	free_all(t_config *config)
{
	free(config->philo);
	free(config->fork);
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
		t_ate = %d\n",
			config->philo[i].id,
			config->philo[i].rfork,
			config->philo[i].lfork,
			config->philo[i].lst_meal,
			config->philo[i].t_ate);
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
