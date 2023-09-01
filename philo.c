/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:53:51 by yamajid           #+#    #+#             */
/*   Updated: 2023/08/28 23:21:10 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philos *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->key_lock);
	printf("%zu %d %s\n", get_time() - philo->data->lunching_time,
		philo->id, msg);
	pthread_mutex_unlock(&philo->data->key_lock);
}

void	routine_plus(t_philos *philos)
{
	pthread_mutex_lock(&philos->data->ml);
	philos->data->f++;
	pthread_mutex_unlock(&philos->data->ml);
}

void	*start_routine(void	*ptr)
{
	t_philos	*philos;

	philos = (t_philos *)ptr;
	if (!is_even(philos->id))
		usleep(200);
	while (philos->x_meals != philos->data->nbr_of_meals)
	{
		pthread_mutex_lock(&philos->left);
		ft_print(philos, "has taken a fork");
		pthread_mutex_lock(philos->right);
		ft_print(philos, "has taken a fork");
		pthread_mutex_lock(&philos->death);
		philos->last_meal = get_time();
		philos->x_meals += (philos->data->nbr_of_meals != -1);
		pthread_mutex_unlock(&philos->death);
		ft_print(philos, "is eating");
		my_sleep(philos->data->time_to_eat);
		pthread_mutex_unlock(&philos->left);
		pthread_mutex_unlock(philos->right);
		ft_print(philos, "is sleeping");
		my_sleep(philos->data->time_to_sleep);
		ft_print(philos, "is thinking");
	}
	routine_plus (philos);
	return (NULL);
}

void	is_died(t_philos *philos)
{
	pthread_mutex_unlock(&philos->death);
	ft_print(philos, "died");
	pthread_mutex_lock(&philos->death);
	pthread_mutex_lock(&philos->data->key_lock);
}

void	check_dead(t_philos *philos, t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->ml);
		if (data->f == data->nbr_of_philos)
		{
			pthread_mutex_unlock(&data->ml);
			break ;
		}
		pthread_mutex_unlock(&data->ml);
		pthread_mutex_lock(&philos[i].death);
		if (get_time() - philos[i].last_meal > 
			(unsigned int)data->time_to_die && philos[i].f != 1)
		{
			is_died(&philos[i]);
			usleep(500);
			break ;
		}
		pthread_mutex_unlock(&philos[i].death);
		i = (i + 1) % data->nbr_of_philos;
	}
}
