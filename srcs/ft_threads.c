/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:46:26 by kricky            #+#    #+#             */
/*   Updated: 2021/09/23 23:54:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

void	ft_threads_destroy(t_collection *phs)
{
	int	i;

	i = 0;
	if (phs->n == 1)
		pthread_detach(phs->philosophers[0].thread_id);
	else
		while (i < phs->n)
		{
			pthread_detach(phs->philosophers[i].thread_id);
			i++;
		}
	i = 0;
	while (i < phs->n)
	{
		pthread_mutex_destroy(&phs->forks[i]);
		i++;
	}
	pthread_mutex_destroy(phs->print);
	free(phs->philosophers);
	free(phs->forks);
}

void	ft_observer(t_collection *phs, t_philosopher *philosopher)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < phs->n && !phs->simulation_stops)
		{
			if ((int)(ft_timestamp() - philosopher[i].eat_time) >= phs->die_time)
			{
				ft_print_status(STATUS_DEAD, philosopher);
				phs->simulation_stops = 1;
			}
			i++;
		}
		if (phs->simulation_stops)
			break ;
		i = 0;
		if (phs->max_eat_counter != -1)
		{
			while (i < phs->n)
			{
				if (philosopher[i].eat_counter >= phs->max_eat_counter)
					phs->simulation_stops = 1;
				i++;
			}
		}
	}
}

void	ft_action_eat(t_philosopher *philosopher)
{
	t_collection	*phs;

	phs = philosopher->phs;
	pthread_mutex_lock(&phs->forks[philosopher->left_fork]);
	ft_print_status(STATUS_LEFT_FORK, philosopher);
	pthread_mutex_lock(&phs->forks[philosopher->right_fork]);
	ft_print_status(STATUS_RIGHT_FORK, philosopher);
	ft_print_status(STATUS_EAT, philosopher);
	philosopher->eat_time = ft_timestamp();
	ft_sleep(phs->eat_time);
	philosopher->eat_counter++;
	pthread_mutex_unlock(&phs->forks[philosopher->right_fork]);
	pthread_mutex_unlock(&phs->forks[philosopher->left_fork]);
}

void	*ft_philosophy(void *obj)
{
	t_philosopher	*philosopher;
	t_collection	*phs;

	philosopher = (t_philosopher *)obj;
	phs = philosopher->phs;
	if (phs->n > 1 && philosopher->index % 2)
		ft_sleep(phs->eat_time);
	while (phs->max_eat_counter != 0)
	{
		ft_action_eat(philosopher);
		ft_print_status(STATUS_SLEEP, philosopher);
		ft_sleep(phs->sleep_time);
		ft_print_status(STATUS_THINK, philosopher);
	}
	return (NULL);
}

void ft_init_threads(t_collection *phs)
{
	int i;

	i = 0;
	phs->start_time = ft_timestamp();
	while (i < phs->n)
	{
		phs->philosophers[i].eat_time = ft_timestamp();
		pthread_create(&phs->philosophers[i].thread_id, NULL, ft_philosophy, &phs->philosophers[i]);
		i++;
	}
	ft_observer(phs, phs->philosophers);
	ft_threads_destroy(phs);
}
