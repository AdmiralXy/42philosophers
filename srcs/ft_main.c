/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:33:51 by kricky            #+#    #+#             */
/*   Updated: 2021/11/19 13:07:41 by kricky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

void	ft_threads_destroy(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->n_philosophers)
	{
		pthread_detach(env->philosophers[i].thread_id);
		pthread_mutex_destroy(env->philosophers->right_fork);
		pthread_mutex_destroy(env->philosophers->left_fork);
		i++;
	}
	i = 0;
	while (i < env->n_philosophers)
	{
		pthread_mutex_destroy(&env->forks[i]);
		i++;
	}
	pthread_mutex_destroy(env->print);
	free(env->print);
	free(env->philosophers);
	free(env->forks);
	free(env);
}

int	ft_observer(t_env *env)
{
	int	i;
	int	time;

	i = -1;
	while (++i < env->n_philosophers)
	{
		time = ft_timestamp()
			- env->philosophers[i].start_time
			- env->philosophers[i].ate_last_time;
		if (time > env->die_time)
		{
			pthread_mutex_lock(env->philosophers[i].print);
			usleep(469);
			if (env->philosophers[i].eat_counter > 0
				|| env->philosophers[i].eat_counter == -1)
				printf("%d %d died\n", ft_timestamp()
					- env->philosophers[i].start_time, i + 1);
			return (EXIT_DEAD);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (1);
	if (argc < 5 || argc > 6)
		return (ft_throw(ERROR_USAGE, 1));
	if (!ft_init(argc, argv, env))
		return (1);
	ft_init_philosophers(env);
	if (ft_init_threads(env) != 0)
	{
		ft_threads_destroy(env);
		return (ft_throw(ERROR_CREATE_THREAD, 1));
	}
	while (1)
	{
		if (!ft_observer(env))
		{
			ft_threads_destroy(env);
			return (0);
		}
	}
}
