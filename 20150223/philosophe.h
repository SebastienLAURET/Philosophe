/*
** philosophe.h for philosophe in /home/rosain_f/rendu/PSU_2014_philo
** 
** Made by Francois Rosain
** Login   <rosain_f@epitech.net>
** 
** Started on  Sun Feb 22 08:36:21 2015 Francois Rosain
** Last update Mon Feb 23 16:04:31 2015 Francois Rosain
*/

#ifndef _PHILO_H_
# define _PHILO_H_

typedef enum	e_stat
{
  SLEEP,
  THINK,
  EAT
}		t_stat;

void	update_images();

void	*handle_philosopher_1(void *args);
void	*handle_philosopher_2(void *args);
void	*handle_philosopher_3(void *args);
void	*handle_philosopher_4(void *args);
void	*handle_philosopher_5(void *args);
void	*handle_philosopher_6(void *args);
void	*handle_philosopher_7(void *args);

#endif /* _PHILO_H_ */
