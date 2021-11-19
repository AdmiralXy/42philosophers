/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:33:51 by kricky            #+#    #+#             */
/*   Updated: 2021/11/18 10:35:09 by kricky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

int	ft_validation(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0)
		return (0);
	if (ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (0);
	if (argc > 5 && ft_atoi(argv[5]) < 0)
		return (0);
	return (1);
}

int	ft_init(int argc, char **argv, t_env *env)
{
	if (!ft_validation(argc, argv))
	{
		free(env);
		return (ft_throw(ERROR_ARGS, 0));
	}
	env->n_philosophers = ft_atoi(argv[1]);
	if (!env->n_philosophers)
	{
		free(env);
		return (0);
	}
	env->die_time = ft_atoi(argv[2]);
	env->eat_time = ft_atoi(argv[3]);
	env->sleep_time = ft_atoi(argv[4]);
	if (argc < 6)
		env->eat_count = -1;
	else
		env->eat_count = ft_atoi(argv[5]);
	env->philosophers = malloc(sizeof(t_philosopher) * env->n_philosophers);
	env->forks = malloc(sizeof(t_mutex) * env->n_philosophers);
	env->print = malloc(sizeof(t_mutex));
	if (!env->forks || !env->philosophers || !env->print)
		return (ft_throw(ERROR_MALLOC, 0));
	env->start_time = ft_timestamp();
	return (1);
}

void	ft_init_philosophers(t_env *env)
{
	int	i;

	i = -1;
	pthread_mutex_init(env->print, NULL);
	while (++i < env->n_philosophers)
		pthread_mutex_init(&env->forks[i], NULL);
	i = -1;
	while (++i < env->n_philosophers)
	{
		env->philosophers[i].index = i + 1;
		env->philosophers[i].eat_time = env->eat_time;
		env->philosophers[i].sleep_time = env->sleep_time;
		env->philosophers[i].ate_last_time = 0;
		env->philosophers[i].left_fork = &env->forks[i];
		env->philosophers[i].right_fork
			= &env->forks[(i + 1) % env->n_philosophers];
		env->philosophers[i].start_time = env->start_time;
		env->philosophers[i].print = env->print;
		env->philosophers[i].eat_counter = env->eat_count;
	}
}
