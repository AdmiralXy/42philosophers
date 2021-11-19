/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:33:51 by kricky            #+#    #+#             */
/*   Updated: 2021/11/18 10:35:09 by kricky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

int	ft_timestamp(void)
{
	struct timeval	time;
	size_t			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000;
	milliseconds += time.tv_usec / 1000;
	return ((int) milliseconds);
}

void	ft_sleep(size_t milliseconds)
{
	size_t	start_time;

	start_time = ft_timestamp();
	while (ft_timestamp() - start_time < milliseconds)
		usleep(50);
}

int	ft_throw(const char *error, int code)
{
	printf("%s: ", PROGRAM_NAME);
	printf("%s\n", error);
	return (code);
}
