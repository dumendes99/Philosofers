/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:00:38 by elima-me          #+#    #+#             */
/*   Updated: 2022/02/09 21:30:55 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	invalid_args(int argc, char **argv)
{
	int	count_args;

	count_args = 0;
	if (argc < 5 || argc > 6)
		return (print_errors(ERR_NUMBERS_ARGS));
	while (argv[++count_args])
	{
		if (is_numeric_chars(argv[++count_args]))
			return (print_errors(ERR_INVALID_ARGS));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (invalid_args(argc, argv))
		return (1);
	return (0);
}
