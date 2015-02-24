/*
** handler_1.c for handler in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:35:19 2015 Sebastien Lauret
** Last update Tue Feb 24 10:08:26 2015 Francois Rosain
*/

#include <stdio.h>
#include "philo.h"

void	*handle_philosopher_1(void *args)
{
  handler(&g_baguette_1, &g_baguette_2, 0);
  return (NULL);
}

void	*handle_philosopher_2(void *args)
{
  handler(&g_baguette_2, &g_baguette_3, 1);
  return (NULL);
}

void	*handle_philosopher_3(void *args)
{
  handler(&g_baguette_3, &g_baguette_4, 2);
  return (NULL);
}

void	*handle_philosopher_4(void *args)
{
  handler(&g_baguette_4, &g_baguette_5, 3);
  return (NULL);
}

void	*handle_philosopher_5(void *args)
{
  handler(&g_baguette_5, &g_baguette_6, 4);
  return (NULL);
}
