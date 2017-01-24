/*
** philo.c for philo in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:35:57 2015 Sebastien Lauret
** Last update Fri Feb 27 13:07:43 2015 Sebastien Lauret
*/

#include <curses.h>
#include <term.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "philo.h"

pthread_mutex_t		tc = PTHREAD_MUTEX_INITIALIZER;
extern pthread_mutex_t	*g_baguette;
extern stat		*g_stat_philo;
extern int		g_nb_riz;

void		display_stat(int id_philo, char *stat)
{
  putp(tgoto(tgetstr("cm", NULL), 0, id_philo));
  printf("philo %d : %s \n", id_philo, stat);
}

void	philo_sleep(int id_philo)
{
  int	philo_left;
  int	philo_right;

  if (id_philo == 0)
    philo_left = NB_PHILO;
  else
    philo_left = id_philo - 1;
  if (id_philo == NB_PHILO)
    philo_right = 0;
  else
    philo_right = id_philo + 1;
  usleep(TIME_SLEEP);
  while (g_stat_philo[philo_left] == THINK
	 || g_stat_philo[philo_right] == THINK);
}

void	philo_eat(pthread_mutex_t *bag_pa,
		  pthread_mutex_t *bag_pn, int id_philo)
{
  g_stat_philo[id_philo] = EAT;

  pthread_mutex_lock(&tc);
  display_stat(id_philo, "EAT  ");
  g_nb_riz -= 1;
  pthread_mutex_unlock(&tc);
  usleep(TIME_EAT);
  pthread_mutex_unlock(bag_pa);
  pthread_mutex_unlock(bag_pn);
  pthread_mutex_lock(&tc);
  display_stat(id_philo, "SLEEP");
  g_stat_philo[id_philo] = SLEEP;
  pthread_mutex_unlock(&tc);
}

void	philo_think(pthread_mutex_t *b_pa, pthread_mutex_t *b_pn,
		    int id_philo, int ind)
{
  g_stat_philo[id_philo] = THINK;
  pthread_mutex_lock(&tc);
  display_stat(id_philo, "THINK");
  pthread_mutex_unlock(&tc);
  usleep(TIME_THINK);
  pthread_mutex_lock(b_pn);
  g_stat_philo[id_philo] = EAT;
  pthread_mutex_lock(&tc);
  ind = !(ind);
  display_stat(id_philo, "EAT  ");
   g_nb_riz -= 1;
  pthread_mutex_unlock(&tc);
   usleep(TIME_EAT);
  pthread_mutex_unlock(b_pn);
  pthread_mutex_unlock(b_pa);
  pthread_mutex_lock(&tc);
  display_stat(id_philo, "SLEEP");
  g_stat_philo[id_philo] = SLEEP;
  pthread_mutex_unlock(&tc);
}
