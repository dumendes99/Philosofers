/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:01:49 by elima-me          #+#    #+#             */
/*   Updated: 2022/02/10 22:14:23 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define ERROR_SIZE 5

# include <stdio.h>

typedef struct s_infoPhilos {
	int	n_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
}	t_infoPhilos;

enum e_errors {
	ERR_INVALID_ARGS,
	ERR_NUMBERS_ARGS,
	ERR_NEGATIVE_NUM,
	ERR_NUMBER_PHILOS,
	ERR_INVALID_VALUE
};

int		main(int argc, char *argv[]);
int		ft_strnotisdigit(char *str);
int		print_errors(int errornum);
int		ft_atoi(const char *str);
int		is_numeric_chars(const char *str);
int		ft_isdigit(int c);
int		invalid_args(int argc, char **argv);
void	ft_bzero(void *s, size_t n);
int		get_info(t_infoPhilos *info_philos, char **argv);
int		game_validator(t_infoPhilos *info_philos, char **argv);
int		setup(int argc, char **argv, t_infoPhilos *info_philos);


#endif