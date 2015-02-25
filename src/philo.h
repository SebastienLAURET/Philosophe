/*
** philo.h for philo in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:35:40 2015 Sebastien Lauret
** Last update Wed Feb 25 18:15:19 2015 Sebastien Lauret
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>

# define TIME_S 1000000

typedef enum	e_stat
{
  SLEEP,
  THINK,
  EAT
}		stat;

typedef struct		s_env{
  pthread_mutex_t	*baguette;
  stat			*stat_philo;
  int			id_philo;
  int			nb_philo;
  int			*nb_riz;
}			t_env;

void	philo_eat(pthread_mutex_t*, pthread_mutex_t*, t_env*);
void	philo_think(pthread_mutex_t*, pthread_mutex_t*, t_env*);
void	philo_sleep(stat*,int, int);
void	action(pthread_mutex_t*, pthread_mutex_t*, t_env*);

void	*handle_philosopher(void *args);
void	handler(pthread_mutex_t*, pthread_mutex_t*, t_env*);

#endif /* !_PHILO_H_*/
