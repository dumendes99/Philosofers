/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:29:41 by elima-me          #+#    #+#             */
/*   Updated: 2022/02/09 21:27:04 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	print_errors(int errornum)
{
	char	*message[ERROR_SIZE];

	message[ERR_INVALID_ARGS] = "Invalid arguments";
	message[ERR_NUMBERS_ARGS] = "Invalid number of arguments";
	message[ERR_NEGATIVE_NUM] = "Please enter only positive numbers";
	printf("Error, %s\n", message[errornum]);
	return (1);
}

int	is_numeric_chars(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((!ft_isdigit(str[i]))
			&& (str[i] != '-' || str[i] != '+'))
			return (1);
	}
	return (0);
}

long int	ft_atoi(const char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (print_errors(ERR_NEGATIVE_NUM));
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
