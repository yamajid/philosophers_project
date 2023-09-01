/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:53:41 by yamajid           #+#    #+#             */
/*   Updated: 2023/08/28 22:53:42 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	pars_data(int ac, char **av, t_data *data)
{
	long	num;

	if (ac != 6 && ac != 5)
		return (1);
	if (!ft_atoi(av[1], &num))
		return (1);
	data->nbr_of_philos = num;
	if (!ft_atoi(av[2], &num))
		return (1);
	data->time_to_die = num;
	if (!ft_atoi(av[3], &num))
		return (1);
	data->time_to_eat = num;
	if (!ft_atoi(av[4], &num))
		return (1);
	data->time_to_sleep = num;
	data->nbr_of_meals = -1;
	if (ac == 6 && (ft_atoi(av[5], &num)))
		data->nbr_of_meals = num;
	else
		data->nbr_of_meals = -1;
	if (ac == 6 && !(ft_atoi(av[5], &num)))
		return (1);
	return (0);
}

int	parse_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+')
			return (-1);
		i++;
	}
	i = 0;
	while (str[i] == '+')
		i++;
	return (i);
}

int	parse_int(long num)
{
	if (num > 2147483647 || num < 0)
		return (1);
	return (0);
}
