/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:49:31 by                   #+#    #+#             */
/*   Updated: 2021/09/23 23:37:14 by                  ###   ########.fr       */
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
# define ERROR_ARGS "Error in arguments!\n"
# define ERROR_USAGE "Usage: [nbr_of_philosophers] [die_time] [eat_time] [slee\
p_time] [optional: number_of_times_each_philosopher_must_eat]\n"
# define ERROR_MALLOC "Error, not enough RAM!\n"
# define STATUS_LEFT_FORK "\033[0;42mhas taken a fork\033[0m"
# define STATUS_RIGHT_FORK "\033[0;41mhas taken a fork\033[0m"
# define STATUS_EAT "is eating"
# define STATUS_SLEEP "is sleeping"
# define STATUS_THINK "is thinking"
# define STATUS_DEAD "died"

// Typedefs
typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

// Structures
typedef struct s_philosopher
{
	int				index;
	int				left_fork;
	int				right_fork;
	size_t			eat_time;
	int				eat_counter;
	t_thread		thread_id;
	void			*phs;
}	t_philosopher;

typedef struct s_collection
{
	int				n;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_eat_counter;
	int 			simulation_stops;
	size_t			start_time;
	t_mutex			*forks;
	t_philosopher	*philosophers;
	t_mutex			*print;
}	t_collection;

// Main functions
int		ft_atoi(const char *str);
int		ft_init(int argc, char **argv, t_collection *env);
void 	ft_sleep(size_t mseconds);
void	ft_init_threads(t_collection *phs);

// Utils
void	ft_print_status(char *status, t_philosopher *philosopher);
int		ft_throw(t_collection *phs, const char *error, int code);
size_t	ft_timestamp();

#endif
