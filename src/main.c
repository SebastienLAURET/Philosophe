/*
** main.c for main in /home/lauret_s/rendu/PSU_2014_philo/src
**
** Made by Sebastien Lauret
** Login   <lauret_s@epitech.net>
**
** Started on  Mon Feb 23 21:36:18 2015 Sebastien Lauret
** Last update Wed Feb 25 16:04:32 2015 Sebastien Lauret
*/

#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

t_env	*init(int nb_philo)
{
  t_env			*ev;
  stat			*stat_philo;
  pthread_mutex_t	*baguette;
  int	*nb_riz;
  int	nb = 0;

  if ((baguette = malloc(sizeof(pthread_mutex_t) * (nb_philo + 1))) == NULL
      || (ev = malloc(sizeof(pthread_mutex_t) * (nb_philo + 1))) == NULL
      || (stat_philo = malloc(sizeof(stat) * (nb_philo + 1))) == NULL
      || (nb_riz = malloc(sizeof(int) * 1)) == NULL)
    return (NULL);
  *nb_riz = 1200;
  while (nb < nb_philo)
    {
      pthread_mutex_init(&baguette[nb], NULL);
      stat_philo[nb] = SLEEP;
      ev[nb].baguette = baguette;
      ev[nb].stat_philo = stat_philo;
      ev[nb].id_philo = nb;
      ev[nb].nb_philo = nb_philo - 1;
      ev[nb].nb_riz = nb_riz;
      nb++;
    }
  return (ev);
}

int	main(int ac, char **av)
{
  t_env		*environement;
  pthread_t	*philosopher;
  int		nb_philo = atoi(av[1]);
  int		nb = 0;

  if ((philosopher = malloc(sizeof(pthread_t) * (nb_philo + 1))) == NULL
      || (environement = init(nb_philo)) == NULL)
    return (-1);
  while (nb <  nb_philo)
    {
      printf ("philo %d - %d / %d\n", nb, environement[nb].id_philo, environement[nb].nb_philo );
      pthread_create(&philosopher[nb], NULL, handle_philosopher, &environement[nb]);
      nb++;
    }
  nb = 0;
  while (nb <  nb_philo)
    {
      pthread_join(philosopher[nb], NULL);
      nb++;
    }
  return (0);
}
