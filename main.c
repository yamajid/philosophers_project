/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:53:29 by yamajid           #+#    #+#             */
/*   Updated: 2023/08/28 22:53:30 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_delete(t_philos *philos)
{
	int	tmp;

	tmp = 0;
	while (tmp < philos->data->nbr_of_philos)
	{
		pthread_mutex_destroy(&philos[tmp].left);
		pthread_mutex_destroy(&philos[tmp].death);
		tmp++;
	}
	free(philos);
}

t_philos	*intilize_philos(t_data *data, t_philos **philos)
{
	t_philos	*philo;
	int			i;

	philo = *philos;
	i = 0;
	data->f = 0;
	pthread_mutex_init(&data->key_lock, NULL);
	pthread_mutex_init(&data->ml, NULL);
	while (i < data->nbr_of_philos)
	{
		pthread_mutex_init(&philo[i].left, NULL);
		pthread_mutex_init(&philo[i].death, NULL);
		if (i == 0)
			philo[i].right = &philo[data->nbr_of_philos -1].left;
		else 
			philo[i].right = &philo[i - 1].left;
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].x_meals = 0;
		i++;
	}
	return (philo);
}

int	create_philos(t_data *data)
{
	t_philos	*philos;
	int			i;

	i = 0;
	philos = malloc(sizeof(t_philos) * data->nbr_of_philos);
	if (philos == NULL)
		return (1);
	intilize_philos(data, &philos);
	data->lunching_time = get_time();
	while (i < data->nbr_of_philos)
	{
		philos[i].last_meal = get_time();
		if (pthread_create(&philos[i].thread, NULL, 
				start_routine, &philos[i]) == -1
			|| pthread_detach(philos[i].thread) != 0)
			return (ft_delete(philos), 1);
		pthread_detach(philos[i].thread);
		i++;
	}
	check_dead(philos, data);
	usleep(5000);
	ft_delete(philos);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (pars_data(ac, av, &data) == 1)
		return (write(2, "ERROR\n", 5));
	if (create_philos(&data) == 1)
		return (1);
	return (0);
}
