/*
** philo.h for philo in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:35:40 2015 Sebastien Lauret
** Last update Fri Feb 27 11:43:48 2015 Sebastien Lauret
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>

# define TIME_SLEEP	10
# define TIME_THINK	1000000
# define TIME_EAT	1000000

# define NB_PHILO	7
# define NB_RIZ		-42

typedef enum	e_stat
  {
    SLEEP,
    THINK,
    EAT
  }		stat;

void	*init();
void	free_all(pthread_t *philosopher);
void	init_termcap();

void	display_baguette(int id_philo, int lock);
void	display_stat(int id_philo, char *stat);
void	philo_eat(pthread_mutex_t*, pthread_mutex_t*, int);
void	philo_think(pthread_mutex_t*, pthread_mutex_t*, int, int);
void	philo_sleep(int);

void	action(pthread_mutex_t*, pthread_mutex_t*, int);
void	*handle_philosopher(void *args);
void	handler(pthread_mutex_t*, pthread_mutex_t*, int);

#endif /* !_PHILO_H_*/
