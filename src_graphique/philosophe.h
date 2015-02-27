/*
** philosophe.h for philosophe in /home/rosain_f/rendu/PSU_2014_philo
** 
** Made by Francois Rosain
** Login   <rosain_f@epitech.net>
** 
** Started on  Sun Feb 22 08:36:21 2015 Francois Rosain
** Last update Fri Feb 27 10:19:51 2015 Francois Rosain
*/

#ifndef _PHILO_H_
# define _PHILO_H_

# define T_UPDATE	500
# define TIME_S		1
# define TIME_E		2

typedef enum	e_stat
{
  SLEEP,
  THINK,
  EAT
}		t_stat;

void	update_images();

void	sleeping(int philo);
void	action(pthread_mutex_t *baguette_pa, pthread_mutex_t *baguette_pn,
	       int philo);
void	handler(pthread_mutex_t *baguette_pa, pthread_mutex_t *baguette_pn,
		int philo);

void	*handle_philosopher_1(void *args);
void	*handle_philosopher_2(void *args);
void	*handle_philosopher_3(void *args);
void	*handle_philosopher_4(void *args);
void	*handle_philosopher_5(void *args);
void	*handle_philosopher_6(void *args);
void	*handle_philosopher_7(void *args);

#endif /* _PHILO_H_ */
