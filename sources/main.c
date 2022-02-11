/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:00:38 by elima-me          #+#    #+#             */
/*   Updated: 2022/02/10 22:13:22 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_infoPhilos info_philos;

	if (setup(argc, argv, &info_philos))
	{
		printf("Caiu no setup\n");
		return (1);
	}
	return (0);
}
