/*
** handler_2.c for handler_2 in /home/rosain_f/rendu/PSU_2014_philo/src_graphique
** 
** Made by Francois Rosain
** Login   <rosain_f@epitech.net>
** 
** Started on  Fri Feb 27 10:16:09 2015 Francois Rosain
** Last update Fri Feb 27 10:23:08 2015 Francois Rosain
*/

#include <pthread.h>
#include "philosophe.h"

extern pthread_mutex_t g_baguette_1;
extern pthread_mutex_t g_baguette_4;
extern pthread_mutex_t g_baguette_5;
extern pthread_mutex_t g_baguette_6;
extern pthread_mutex_t g_baguette_7;

void	*handle_philosopher_4(void *args)
{
  (void) args;
  handler(&g_baguette_4, &g_baguette_5, 3);
  return (NULL);
}

void	*handle_philosopher_5(void *args)
{
  (void) args;
  handler(&g_baguette_5, &g_baguette_6, 4);
  return (NULL);
}

void	*handle_philosopher_6(void *args)
{
  (void) args;
  handler(&g_baguette_6, &g_baguette_7, 5);
  return (NULL);
}

void	*handle_philosopher_7(void *args)
{
  (void) args; 
  handler(&g_baguette_7, &g_baguette_1, 6);
  return (NULL);
}
