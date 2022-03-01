/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:01:49 by elima-me          #+#    #+#             */
/*   Updated: 2022/03/01 18:29:58 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define ERROR_SIZE 5

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_config	t_config;
typedef struct s_philo	t_philo;

struct s_philo {
	int			id;
	int			t_ate;
	int			rfork;
	int			lfork;
	long int	lst_meal;
	t_config	*config;
	pthread_t	thread;
};

struct s_config {
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				times_must_eat;
	int				should_stop;
	long int		sim_start;
	pthread_t		monitor;
	t_philo			*philo;
	pthread_mutex_t	*fork;
};

enum e_errors {
	ERR_INVALID_ARGS,
	ERR_NUMBERS_ARGS,
	ERR_NEGATIVE_NUM,
	ERR_NUMBER_PHILOS,
	ERR_INVALID_VALUE
};

int			main(int argc, char *argv[]);
int			ft_strnotisdigit(char *str);
int			print_errors(int errornum);
int			ft_atoi(const char *str);
int			is_numeric_chars(const char *str);
int			ft_isdigit(int c);
int			invalid_args(int argc, char **argv);
void		ft_bzero(void *s, size_t n);
int			get_info(t_config *info_philos, char **argv);
int			invalid_simulation(t_config *info_philos, char **argv);
int			setup(int argc, char **argv, t_config *info_philos);
void		*routine(void *sett);
void		print_infos(t_config *config);
int			free_all(t_config *config);
long int	get_now(void);
int			start_banquet(t_config *config);
void		eat(t_philo *philo);
int			print_status(long int now, t_philo *philo, char *status);
void		*monitor_routine(void *sett);
int			should_stop(t_config *config);

#endif
