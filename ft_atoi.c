/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:53:33 by yamajid           #+#    #+#             */
/*   Updated: 2023/08/28 22:53:34 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str, long *num)
{
	int		i;
	long	result;

	result = 0;
	i = parse_str(str);
	if (i == -1)
		return (0);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10;
		result += str[i] - 48;
		i++;
	}
	*num = result;
	if (parse_int(*num) == 1 || result == 0)
		return (0);
	return (1);
}
