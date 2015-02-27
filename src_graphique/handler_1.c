/*
** handler_1.c for handler_1 in /home/rosain_f/rendu/PSU_2014_philo/src_graphique
** 
** Made by Francois Rosain
** Login   <rosain_f@epitech.net>
** 
** Started on  Fri Feb 27 10:15:36 2015 Francois Rosain
** Last update Fri Feb 27 10:23:04 2015 Francois Rosain
*/

#include <pthread.h>
#include "philosophe.h"

extern pthread_mutex_t g_baguette_1;
extern pthread_mutex_t g_baguette_2;
extern pthread_mutex_t g_baguette_3;
extern pthread_mutex_t g_baguette_4;

void	handler(pthread_mutex_t *baguette_pa, pthread_mutex_t *baguette_pn,
		int philo)
{
  while (1)
    {
      sleeping(philo);
      action(baguette_pa, baguette_pn, philo);
    }
}

void	*handle_philosopher_1(void *args)
{
  (void) args;
  handler(&g_baguette_1, &g_baguette_2, 0);
  return (NULL);
}

void	*handle_philosopher_2(void *args)
{
  (void) args;
  handler(&g_baguette_2, &g_baguette_3, 1);
  return (NULL);
}

void	*handle_philosopher_3(void *args)
{
  (void) args;
  handler(&g_baguette_3, &g_baguette_4, 2);
  return (NULL);
}

