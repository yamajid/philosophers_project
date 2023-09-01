/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:53:58 by yamajid           #+#    #+#             */
/*   Updated: 2023/08/28 22:53:59 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_even(int nbr)
{
	if (nbr % 2 == 0)
		return (0);
	else 
		return (1);
}

size_t	get_time(void)
{
	size_t			time;
	struct timeval	t;

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (time);
}

int	my_sleep(int ms)
{
	size_t	start;

	start = get_time();
	while (((get_time() - start) < (size_t)ms))
		usleep(200);
	return (0);
}
