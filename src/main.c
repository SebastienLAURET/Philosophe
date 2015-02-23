/*
** main.c for main in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:36:18 2015 Sebastien Lauret
** Last update Mon Feb 23 21:36:20 2015 Sebastien Lauret
*/

#include <pthread.h>
#include "philo.h"

pthread_mutex_t g_baguette_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_5 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_6 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_7 = PTHREAD_MUTEX_INITIALIZER;
stat		g_stat_philo[7] =
  {
    SLEEP,
    SLEEP,
    SLEEP,
    SLEEP,
    SLEEP,
    SLEEP,
    SLEEP
  };


int	main()
{
  pthread_t	philosopher_1;
  pthread_t	philosopher_2;
  pthread_t	philosopher_3;
  pthread_t	philosopher_4;
  pthread_t	philosopher_5;
  pthread_t	philosopher_6;
  pthread_t	philosopher_7;

  pthread_create(&philosopher_1, NULL, handle_philosopher_1, NULL);
  pthread_create(&philosopher_2, NULL, handle_philosopher_2, NULL);
  pthread_create(&philosopher_3, NULL, handle_philosopher_3, NULL);
  pthread_create(&philosopher_4, NULL, handle_philosopher_4, NULL);
  pthread_create(&philosopher_5, NULL, handle_philosopher_5, NULL);
  pthread_create(&philosopher_6, NULL, handle_philosopher_6, NULL);
  pthread_create(&philosopher_7, NULL, handle_philosopher_7, NULL);
  pthread_join(philosopher_1, NULL);
  pthread_join(philosopher_2, NULL);
  pthread_join(philosopher_3, NULL);
  pthread_join(philosopher_4, NULL);
  pthread_join(philosopher_5, NULL);
  pthread_join(philosopher_6, NULL);
  pthread_join(philosopher_7, NULL);
  return (0);
}
