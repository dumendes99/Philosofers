/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:00:38 by elima-me          #+#    #+#             */
/*   Updated: 2022/02/24 20:18:43 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*routine(void *param)
{
	(void)param;
	for (int i = 0; i < 100; i++);
	return (0);
}

int	start_banquet(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->n_philos)
	{
		pthread_create(&config->philo[i].thread, NULL, &routine, NULL);
		printf("The i was incremented\n");
		pthread_join(config->philo->thread, NULL);
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
