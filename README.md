## Minitalk

### About project

* One or more philosophers are sitting at a round table either eating, either thinking,
either sleeping. While they are eating, they do not think or sleep; while thinking
they don’t eat or sleep; and, of course, while sleeping, they do not eat or think.
* The philosophers sit at a circular table with a large bowl of spaghetti in the center.
* There are some forks on the table. Serving and eating spaghetti with a single fork
is very inconvenient, so the philosophers will eat with two forks, one for each hand.
* Each time a philosopher finishes eating, they will drop their forks and start sleeping.
Once they have finished sleeping, they will start thinking. The simulation stops
when a philosopher dies.
* Every philosopher needs to eat and they should never starve.
* Philosophers don’t speak with each other.
* Philosophers don’t know when another philosopher is about to die.
* Philosophers should avoid dying.


* Each philosopher should be a thread.
* One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.
* To avoid philosophers duplicating forks, there is forks state protection with a mutex for each of them.
* Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in milliseconds):
  * timestamp_in_ms X some_action

All functions are created in accordance with [Norm](https://github.com/42School/norminette) - the bunch of rules how code should be formatted.

### Requirements & usage
Project requires:
* C Lang compiler: **gcc** or **clang**
* Possibility to work with Makefile

Tested on:
* MacOS 10.15

Usage:
* ./philo [nbr_of_philosophers] [die_time] [eat_time] [sleep_time] [optional: number_of_times_each_philosopher_must_eat]

Run:
```
$> ./philo 2 800 200 200 1
$> 0 1 has taken a fork
$> 0 1 has taken a fork
$> 0 1 is eating
$> 200 1 is sleeping
$> 200 2 has taken a fork
$> 200 2 has taken a fork
$> 200 2 is eating
$> 400 2 is sleeping
$> 400 1 is thinking
$> 600 2 is thinking
```

### Makefile commands

* make / make all / make push_swap - compile project
* make *.o - compile specific source file
* make clean - clean all object files
* make fclean - clean all object files & library
* make norme - check that all functions are created in accordance with Norm