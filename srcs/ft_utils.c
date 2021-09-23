/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:46:26 by kricky            #+#    #+#             */
/*   Updated: 2021/09/22 19:31:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

void	ft_print_status(char *status, t_philosopher *philosopher)
{
	size_t	time;
	t_collection *phs;

	phs = philosopher->phs;
	if (!phs->simulation_stops)
	{
		pthread_mutex_lock(phs->print);
		time = ft_timestamp() - phs->start_time;
		printf("%ld %d %s\n", time, philosopher->index, status);
		pthread_mutex_unlock(phs->print);
	}
}

int	ft_throw(t_collection *phs, const char *error, int code)
{
	printf("%s", error);
	free(phs);
	return (code);
}

void 	ft_sleep(size_t mseconds)
{
	size_t start_time;

	start_time = ft_timestamp();
	while (ft_timestamp() - start_time < mseconds)
		usleep(1);
}

size_t	ft_timestamp()
{
	struct timeval	time;
	size_t			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000;
	milliseconds += time.tv_usec / 1000;
	return (milliseconds);
}
