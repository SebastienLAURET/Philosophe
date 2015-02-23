#include <stdio.h>
#include "philo.h"

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
