/*
** handler_2.c for handler in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:35:05 2015 Sebastien Lauret
** Last update Wed Feb 25 16:16:31 2015 Sebastien Lauret
*/

#include <stdio.h>
#include "philo.h"

void	handler(pthread_mutex_t *bag_pa, pthread_mutex_t *bag_pn, t_env *philo)
{
  while (*philo->nb_riz > philo->nb_philo - 1)
    {
      philo_sleep(philo->stat_philo, philo->id_philo, philo->nb_philo);
      action(bag_pa, bag_pn, philo);
      printf ("%d \n", *philo->nb_riz);
    }
}

void	*handle_philosopher(void *args)
{
  int	philo_left;
  int	philo_right;
  t_env	*env;

  env = args;
  handler(&(env->baguette[env->id_philo]),
	  &(env->baguette[(env->id_philo == env->nb_philo)? 0 : env->id_philo + 1]), env);
  return (NULL);
}
