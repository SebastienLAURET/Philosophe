/*
** simulator.c for philosopher in /home/rosain_f/rendu/PSU_2014_philo
** 
** Made by Francois Rosain
** Login   <rosain_f@epitech.net>
** 
** Started on  Sun Feb 22 08:35:12 2015 Francois Rosain
** Last update Mon Feb 23 16:21:52 2015 Francois Rosain
*/

#include <pthread.h>
#include <stdio.h>
#include "philosophe.h"

#define TIME_S	1

pthread_mutex_t g_baguette_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_5 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_6 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_7 = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;

t_stat		g_stat_philo[7] = {
  SLEEP,
  SLEEP,
  SLEEP,
  SLEEP,
  SLEEP,
  SLEEP,
  SLEEP
};

void	sleeping(int philo)
{
  int	philo_left;
  int	philo_right;

  philo_left = 0;
  philo_right = 0;
  if (philo == 0)
    philo_left = 6;
  else
    philo_left = philo - 1;
  if (philo == 6)
    philo_right = 0;
  else
    philo_right = philo + 1;
  g_stat_philo[philo] = SLEEP;
  printf("philo %d : SLEEP\n", philo);
  while (g_stat_philo[philo_left] == THINK
	 || g_stat_philo[philo_right] == THINK);
}

void	action(pthread_mutex_t *baguette_pa, pthread_mutex_t *baguette_pn, int philo)
{
  int	ret1;
  int	ret2;

  while (1)
    {
      ret1 = pthread_mutex_trylock(baguette_pa);
      ret2 = pthread_mutex_trylock(baguette_pn);
      if (ret1 == 0 && ret2 == 0)
	{
	  g_stat_philo[philo] = EAT;
	  	  printf("philo %d : EAT\n", philo);
	  sleep(TIME_S);
	  pthread_mutex_unlock(baguette_pa);
	  pthread_mutex_unlock(baguette_pn);
	  break;
	}
      else if (ret1 == 0)
	{
	  g_stat_philo[philo] = THINK;
	  printf("philo %d : THINK\n", philo);
	  sleep(TIME_S);
	  pthread_mutex_lock(baguette_pn);
	  printf("philo %d : EAT\n", philo);
	  g_stat_philo[philo] = EAT;
	  sleep(TIME_S);
	  pthread_mutex_unlock(baguette_pa);
	  pthread_mutex_unlock(baguette_pn);
	  break;
	}
      else if (ret2 == 0)
	{
	  g_stat_philo[philo] = THINK;
	  printf("philo %d : THINK\n", philo);
	  sleep(TIME_S);
	  pthread_mutex_lock(baguette_pa);
	  g_stat_philo[philo] = EAT;
	  printf("philo %d : EAT\n", philo);
	  sleep(TIME_S);
	  pthread_mutex_unlock(baguette_pa);
	  pthread_mutex_unlock(baguette_pn);
	  break;
	}
    }
}

void	handler(pthread_mutex_t *baguette_pa, pthread_mutex_t *baguette_pn, int	philo)
{
  while (1)
    {
      sleeping(philo);
      action(baguette_pa, baguette_pn, philo);
    }
}

void	*handle_philosopher_1(void *args)
{
  (void)(args);
  handler(&g_baguette_1, &g_baguette_2, 0);
  return (NULL);
}

void	*handle_philosopher_2(void *args)
{
  (void)(args);
  handler(&g_baguette_2, &g_baguette_3, 1);
  return (NULL);
}

void	*handle_philosopher_3(void *args)
{
  (void)(args);
  handler(&g_baguette_3, &g_baguette_4, 2);
  return (NULL);
}

void	*handle_philosopher_4(void *args)
{
  (void)(args);
  handler(&g_baguette_4, &g_baguette_5, 3);
  return (NULL);
}

void	*handle_philosopher_5(void *args)
{
  (void)(args);
  handler(&g_baguette_5, &g_baguette_6, 4);
  return (NULL);
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
