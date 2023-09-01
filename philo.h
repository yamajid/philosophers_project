/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:53:55 by yamajid           #+#    #+#             */
/*   Updated: 2023/08/28 22:53:56 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct data
{
	pthread_mutex_t		key_lock;
	pthread_mutex_t		ml;
	long				lunching_time;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_of_meals;
	int					f;
	int					nbr_of_philos;
	int					is_died;
}		t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_data			*data;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
	pthread_mutex_t	death;
	long			last_meal;
	int				x_meals;
	int				f;
}		t_philos;

void	check_dead(t_philos *philos, t_data *data);
void	ft_print(t_philos *philo, char *msg);
void	*start_routine(void	*ptr);
void	ft_delete(t_philos *philos);
size_t	get_time(void);
int		pars_data(int ac, char **av, t_data *data);
int		ft_atoi(char *str, long *num);
int		create_philos(t_data *data);
int		parse_str(char *str);
int		parse_int(long num);
int		my_sleep(int ms);
int		is_even(int nbr);

#endif
