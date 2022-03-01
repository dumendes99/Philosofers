/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:00:38 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/01 14:58:27 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
