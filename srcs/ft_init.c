/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:46:26 by kricky            #+#    #+#             */
/*   Updated: 2021/09/21 19:30:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

int	ft_init_collection(t_collection *phs)
{
	int	i;

	i = 0;
	while (i < phs->n)
	{
		phs->philosophers[i].index = i + 1;
		phs->philosophers[i].left_fork = i;
		phs->philosophers[i].right_fork = (i + 1) % phs->n;
		phs->philosophers[i].eat_counter = 0;
		phs->philosophers[i].phs = phs;
		if (pthread_mutex_init(&(phs->forks[i]), NULL))
			return (0);
		i++;
	}
	return (1);
}

int	ft_validation(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 0)
		return (0);
	if (ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (0);
	if (argc > 5 && ft_atoi(argv[5]) < 0)
		return (0);
	return (1);
}

int	ft_init(int argc, char **argv, t_collection *phs)
{
	if (!ft_validation(argc, argv))
		return (ft_throw(phs, ERROR_ARGS, 0));
	phs->simulation_stops = 0;
	phs->n = ft_atoi(argv[1]);
	phs->die_time = ft_atoi(argv[2]);
	phs->eat_time = ft_atoi(argv[3]);
	phs->sleep_time = ft_atoi(argv[4]);
	if (argc > 5)
		phs->max_eat_counter = ft_atoi(argv[5]);
	else
		phs->max_eat_counter = -1;
	phs->forks = malloc(sizeof(t_mutex) * phs->n);
	phs->philosophers = malloc(sizeof(t_philosopher) * phs->n);
	phs->print = malloc(sizeof(t_mutex));
	if (!phs->forks || !phs->philosophers || !ft_init_collection(phs))
		return (ft_throw(phs, ERROR_MALLOC, 0));
	return (1);
}
