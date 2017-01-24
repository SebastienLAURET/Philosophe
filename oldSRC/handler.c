/*
** handler_2.c for handler in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:35:05 2015 Sebastien Lauret
** Last update Fri Feb 27 11:51:33 2015 Sebastien Lauret
*/

#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

extern pthread_mutex_t	*g_baguette;
extern int		g_nb_riz;

void	handler(pthread_mutex_t *bag_pa,
		pthread_mutex_t *bag_pn, int id_philo)
{
  while (NB_RIZ == -42 || g_nb_riz > NB_PHILO - 1)
    {
      philo_sleep(id_philo);
      action(bag_pa, bag_pn, id_philo);
    }
}

void	*handle_philosopher(void *args)
{
  int	id_philo;

  id_philo = *((int*)args);
  free(args);
  handler(&(g_baguette[id_philo]),
	  &(g_baguette[((id_philo + 1 < NB_PHILO)? id_philo + 1 : 0)]), id_philo);
  return (NULL);
}

void	action(pthread_mutex_t *bag_pa,
	       pthread_mutex_t *bag_pn, int id_philo)
{
  int	ret1;
  int	ret2;

  while (1)
    {
      ret1 = pthread_mutex_trylock(bag_pa);
      ret2 = pthread_mutex_trylock(bag_pn);
      if (ret1 == 0 && ret2 == 0)
	{
	  philo_eat(bag_pa, bag_pn, id_philo);
	  break;
	}
      else if (ret1 == 0)
	{
	  philo_think(bag_pa, bag_pn, id_philo, 0);
	  break;
	}
      else if (ret2 == 0)
	{
	  philo_think(bag_pn, bag_pa, id_philo, 1);
	  break;
	}
    }
}
