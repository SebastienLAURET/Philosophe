#include <pthread.h>
#include <stdio.h>
#include "philo.h"

void	sleep(int philo)
{
  int	philo_left;
  int	philo_right;

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

void	philo_eat(pthread_mutex_t *bag_pa, pthread_mutex_t *bag_pn, int philo)
{
  g_stat_philo[philo] = EAT;
  printf("philo %d : EAT\n", philo);
  usleep(TIME_S);
  pthread_mutex_unlock(bag_pa);
  pthread_mutex_unlock(bag_pn);
}

void	philo_think_1(pthread_mutex_t *b_pa, pthread_mutex_t *b_pn, int philo)
{
  g_stat_philo[philo] = THINK;
  printf("philo %d : THINK\n", philo);
  usleep(TIME_S);
  pthread_mutex_lock(b_pn);
  g_stat_philo[philo] = EAT;
  printf("philo %d : EAT\n", philo);
  usleep(TIME_S);
  pthread_mutex_unlock(b_pa);
  pthread_mutex_unlock(b_pn);
}

void	philo_think_2(pthread_mutex_t *b_pa, pthread_mutex_t *b_pn, int philo)
{
  g_stat_philo[philo] = THINK;
  printf("philo %d : THINK\n", philo);
  usleep(TIME_S);
  pthread_mutex_lock(b_pa);
  g_stat_philo[philo] = EAT;
  printf("philo %d : EAT\n", philo);
  usleep(TIME_S);
  pthread_mutex_unlock(b_pa);
  pthread_mutex_unlock(b_pn);
}

void	action(pthread_mutex_t *bag_pa, pthread_mutex_t *bag_pn, int philo)
{
  int	ret1;
  int	ret2;

  while (1)
    {
      ret1 = pthread_mutex_trylock(bag_pa);
      ret2 = pthread_mutex_trylock(bag_pn);
      if (ret1 == 0 && ret2 == 0)
	{
	  philo_eat(bag_pa, bag_pn, philo);
	  break;
	}
      else if (ret1 == 0)
	{
	  philo_think_1(bag_pa, bag_pn, philo);
	  break;
	}
      else if (ret2 == 0)
	{
	  philo_think_2(bag_pa, bag_pn, philo);
	  break;
	}
    }
}
