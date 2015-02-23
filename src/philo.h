/*
** philo.h for philo in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:35:40 2015 Sebastien Lauret
** Last update Mon Feb 23 21:39:19 2015 Sebastien Lauret
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>

# define TIME_S 1

typedef enum	e_stat
{
  SLEEP,
  THINK,
  EAT
} stat;

void	philo_eat(pthread_mutex_t*, pthread_mutex_t*, int);
void	philo_think_1(pthread_mutex_t*, pthread_mutex_t*, int);
void	philo_think_2(pthread_mutex_t*, pthread_mutex_t*, int);
void	philo_sleep(int philo);
void	action(pthread_mutex_t*, pthread_mutex_t*, int);

void	*handle_philosopher_1(void *args);
void	*handle_philosopher_2(void *args);
void	*handle_philosopher_3(void *args);
void	*handle_philosopher_4(void *args);
void	*handle_philosopher_5(void *args);

void	*handle_philosopher_6(void *args);
void	*handle_philosopher_7(void *args);
void	handler(pthread_mutex_t*, pthread_mutex_t*, int);

extern pthread_mutex_t	g_baguette_1;
extern pthread_mutex_t	g_baguette_2;
extern pthread_mutex_t	g_baguette_3;
extern pthread_mutex_t	g_baguette_4;
extern pthread_mutex_t	g_baguette_5;
extern pthread_mutex_t	g_baguette_6;
extern pthread_mutex_t	g_baguette_7;
extern stat		g_stat_philo[7];

#endif /*PHILO_H_*/
