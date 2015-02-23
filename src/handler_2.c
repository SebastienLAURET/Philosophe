/*
** handler_2.c for handler in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:35:05 2015 Sebastien Lauret
** Last update Mon Feb 23 21:39:44 2015 Sebastien Lauret
*/

#include <stdio.h>
#include "philo.h"

void	handler(pthread_mutex_t *bag_pa, pthread_mutex_t *bag_pn, int philo)
{
  while (1)
    {
      philo_sleep(philo);
      action(bag_pa, bag_pn, philo);
    }
}

void	*handle_philosopher_6(void *args)
{
  (void)(args);
  handler(&g_baguette_6, &g_baguette_7, 5);
  return (NULL);
}

void	*handle_philosopher_7(void *args)
{
  (void)(args);
  handler(&g_baguette_7, &g_baguette_1, 6);
  return (NULL);
}
