/*
** main.c for main in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:36:18 2015 Sebastien Lauret
** Last update Fri Feb 27 11:52:58 2015 Sebastien Lauret
*/

#include <stdlib.h>
#include <pthread.h>
#include <ncurses/curses.h>
#include <term.h>
#include "philo.h"

pthread_mutex_t		*g_baguette;
stat			*g_stat_philo;
int			g_nb_riz;

void		*init()
{
  int		nb = 0;

  if ((g_baguette = malloc(sizeof(pthread_mutex_t) * (NB_PHILO + 1))) == NULL
      || (g_stat_philo = malloc(sizeof(stat) * (NB_PHILO + 1))) == NULL)
    return (NULL);
  while (nb < NB_PHILO)
    {
      pthread_mutex_init(&g_baguette[nb], NULL);
      g_stat_philo[nb] = SLEEP;
      nb++;
    }
  g_nb_riz = NB_RIZ;
  return (malloc(sizeof(pthread_t) * (NB_PHILO + 1)));
}

void		free_all(pthread_t *philosopher)
{
  free(g_baguette);
  free(g_stat_philo);
  free(philosopher);
}

void		init_termcap()
{
  tgetent(NULL, NULL);
  putp(tgetstr("cl", NULL));
}

int		main()
{
  pthread_t	*philosopher;
  int		*nb;
  int		i;

  init_termcap();
  if ((philosopher = init()) == NULL)
    return (-1);
  i = -1;
  while (++i < NB_PHILO)
    {
      if ((nb = malloc(sizeof(int) * 1)) == NULL)
	return (-1);
      *nb = i;
      pthread_create(&philosopher[i], NULL,
		     handle_philosopher, nb);
    }
  i = -1;
  while (++i < NB_PHILO)
    pthread_join(philosopher[i], NULL);
  free_all(philosopher);
  return (0);
}
