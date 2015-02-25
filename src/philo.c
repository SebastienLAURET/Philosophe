/*
** philo.c for philo in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:35:57 2015 Sebastien Lauret
** Last update Wed Feb 25 18:19:56 2015 Sebastien Lauret
*/

#include <ncurses/curses.h>
#include <term.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "philo.h"

pthread_mutex_t	tc = PTHREAD_MUTEX_INITIALIZER;

void            go_to(unsigned int x, unsigned int y)
{
  putp(tgoto(tgetstr("cm", NULL), x, y));
}

void	philo_sleep(stat *stat_philo,int philo, int nb_philo)
{
  int	philo_left;
  int	philo_right;

  if (philo == 0)
    philo_left = nb_philo;
  else
    philo_left = philo - 1;
  if (philo == nb_philo)
    philo_right = 0;
  else
    philo_right = philo + 1;
  stat_philo[philo] = SLEEP;

  pthread_mutex_lock(&tc);
  go_to(0, philo);
  printf("philo %d : SLEEP\n", philo);
  go_to(0, nb_philo);
  pthread_mutex_unlock(&tc);
  usleep(TIME_S/100);
  while (stat_philo[philo_left] == THINK
	 || stat_philo[philo_right] == THINK);
}

void	philo_eat(pthread_mutex_t *bag_pa, pthread_mutex_t *bag_pn, t_env *philo)
{
  philo->stat_philo[philo->id_philo] = EAT;

  pthread_mutex_lock(&tc);
  go_to(0, philo->id_philo);
  printf("philo %d : EAT  \n", philo->id_philo);
  *philo->nb_riz -= 1;
  go_to(0, philo->nb_philo);
  pthread_mutex_unlock(&tc);

  usleep(TIME_S * 2);
  pthread_mutex_unlock(bag_pa);
  pthread_mutex_unlock(bag_pn);
}

void	philo_think(pthread_mutex_t *b_pa, pthread_mutex_t *b_pn, t_env *philo)
{
  philo->stat_philo[philo->id_philo] = THINK;

  pthread_mutex_lock(&tc);
  go_to(0, philo->id_philo);
  printf("philo %d : THINK\n", philo->id_philo);
  go_to(0, philo->nb_philo);
  pthread_mutex_unlock(&tc);

  usleep(TIME_S);
  pthread_mutex_lock(b_pn);
  philo->stat_philo[philo->id_philo] = EAT;

  pthread_mutex_lock(&tc);
  go_to(0, philo->id_philo);
  printf("philo %d : EAT  \n", philo->id_philo);
  *philo->nb_riz -= 1;
  go_to(0, philo->nb_philo);
  pthread_mutex_unlock(&tc);

  usleep(TIME_S * 2);
  pthread_mutex_unlock(b_pn);
  pthread_mutex_unlock(b_pa);
}
void	action(pthread_mutex_t *bag_pa, pthread_mutex_t *bag_pn, t_env *philo)
{
  int	ret1;
  int	ret2;

  while (*philo->nb_riz > 0 || 1)
    {
      ret1 = pthread_mutex_trylock(bag_pa);
      ret2 = pthread_mutex_trylock(bag_pn);
      if (ret1 == 0 && ret2 == 0)
	philo_eat(bag_pa, bag_pn, philo);
      else if (ret1 == 0)
	philo_think(bag_pa, bag_pn, philo);
      else if (ret2 == 0)
	philo_think(bag_pn, bag_pa, philo);
      if (ret1 == 0 || ret2 == 0)
	return;
    }
}
