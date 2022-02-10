/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:01:49 by elima-me          #+#    #+#             */
/*   Updated: 2022/02/09 21:29:35 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define ERROR_SIZE 3

# include <stdio.h>

enum e_errors {
	ERR_INVALID_ARGS,
	ERR_NUMBERS_ARGS,
	ERR_NEGATIVE_NUM
};


int			main(int argc, char *argv[]);
int			ft_strnotisdigit(char *str);
int			print_errors(int errornum);
long int	ft_atoi(const char *str);
int			is_numeric_chars(const char *str);
int			ft_isdigit(int c);
int			invalid_args(int argc, char **argv);

#endif