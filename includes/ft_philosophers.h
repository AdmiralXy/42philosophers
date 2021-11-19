/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:33:51 by kricky            #+#    #+#             */
/*   Updated: 2021/11/18 10:35:09 by kricky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

// Constants
# define PROGRAM_NAME			"42philosophers"
# define EXIT_DEAD				0
# define ERROR_ARGS				"error: the specified arguments are invalid!"
# define ERROR_USAGE			"usage: [nbr_of_philosophers] [die_time] \
[eat_time] [sleep_time] [optional: number_of_times_each_philosopher_must_eat]"
# define ERROR_MALLOC			"error: not enough RAM!"
# define ERROR_CREATE_THREAD	"error: can't properly create threads!"

// Typedefs
typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

// Structures
typedef struct s_philosopher
{
	t_thread	thread_id;
	int			index;
	int			ate_last_time;
	int			sleep_time;
	int			eat_time;
	int			start_time;
	int			eat_counter;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		*print;
}	t_philosopher;

typedef struct s_env
{
	int				start_time;
	int				n_philosophers;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				eat_count;
	t_mutex			*print;
	t_philosopher	*philosophers;
	t_mutex			*forks;
}	t_env;

// Initialization functions
int		ft_init(int argc, char **argv, t_env *env);
void	ft_init_philosophers(t_env *env);
int		ft_init_threads(t_env *env);

// Main functions

// Utilities functions
int		ft_timestamp(void);
void	ft_sleep(size_t milliseconds);
int		ft_atoi(const char *str);
int		ft_throw(const char *error, int code);

#endif