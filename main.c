#include <pthread.h>
#include <stdio.h>

#define TIME_S	1
typedef enum	e_stat
{
  SLEEP,
  THINK,
  EAT
} stat;

pthread_mutex_t g_baguette_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_5 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_6 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_7 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;
stat		g_stat_philo[7] = {SLEEP,
				   SLEEP,
				   SLEEP,
				   SLEEP,
				   SLEEP,
				   SLEEP,
				   SLEEP};

void	sleep(int philo)
{
  int	philo_left;
  int	philo_right;

  if (philo == 1)
    philo_left = 7;
  else
    philo_left = philo - 1;
  if (philo == 7)
    philo_right = 1;
  else
    philo_left = philo + 1;
  g_stat_philo[philo] = SLEEP;
  printf("philo %d : SLEEP\n", philo);
  while (g_stat_philo[philo_left] == THINK
	 || g_stat_philo[philo_right] == THINK);
}

void	actionn(pthread_mutex_t *baguette_pa, pthread_mutex_t *baguette_pn, int philo)
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
	  usleep(TIME_S);
	  pthread_mutex_unlock(baguette_pa);
	  pthread_mutex_unlock(baguette_pn);
	  break;
	}
      else if (ret1 == 0)
	{
	  g_stat_philo[philo] = THINK;
	  printf("philo %d : THINK\n", philo);
	  usleep(TIME_S);
	  pthread_mutex_lock(baguette_pn);
	  printf("philo %d : EAT\n", philo);
	  usleep(TIME_S);
	  pthread_mutex_unlock(baguette_pa);
	  pthread_mutex_unlock(baguette_pn);
	  break;
	}
      else if (ret2 == 0)
	{
	  g_stat_philo[philo] = THINK;
	  printf("philo %d : THINK\n", philo);
	  usleep(TIME_S);
	  pthread_mutex_lock(baguette_pa);
	  printf("philo %d : EAT\n", philo);
	  usleep(TIME_S);
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
      sleep(philo);
      actionn(baguette_pa, baguette_pn, philo);
    }
}

void	*handle_philosopher_1(void *args)
{
  (void)(args);
  handler(&g_baguette_1, &g_baguette_2, 1);
  return (NULL);
}

void	*handle_philosopher_2(void *args)
{
  (void)(args);
  handler(&g_baguette_2, &g_baguette_3, 2);
  return (NULL);
}

void	*handle_philosopher_3(void *args)
{
  (void)(args);
  handler(&g_baguette_3, &g_baguette_4, 3);
  return (NULL);
}

void	*handle_philosopher_4(void *args)
{
  (void)(args);
  handler(&g_baguette_4, &g_baguette_5, 4);
  return (NULL);
}

void	*handle_philosopher_5(void *args)
{
  (void)(args);
  handler(&g_baguette_5, &g_baguette_6, 5);
  return (NULL);
}

void	*handle_philosopher_6(void *args)
{
  (void)(args);
  handler(&g_baguette_6, &g_baguette_7, 6);
  return (NULL);
}

void	*handle_philosopher_7(void *args)
{
  (void)(args);
  handler(&g_baguette_7, &g_baguette_1, 7);
  return (NULL);
}

int	main()
{
  pthread_t	philosopher_1;
  pthread_t	philosopher_2;
  pthread_t	philosopher_3;
  pthread_t	philosopher_4;
  pthread_t	philosopher_5;
  pthread_t	philosopher_6;
  pthread_t	philosopher_7;

  pthread_create(&philosopher_1, NULL, handle_philosopher_1, NULL);
  pthread_create(&philosopher_2, NULL, handle_philosopher_2, NULL);
  pthread_create(&philosopher_3, NULL, handle_philosopher_3, NULL);
  pthread_create(&philosopher_4, NULL, handle_philosopher_4, NULL);
  pthread_create(&philosopher_5, NULL, handle_philosopher_5, NULL);
  pthread_create(&philosopher_6, NULL, handle_philosopher_6, NULL);
  pthread_create(&philosopher_7, NULL, handle_philosopher_7, NULL);
  pthread_join(philosopher_1, NULL);
  pthread_join(philosopher_2, NULL);
  pthread_join(philosopher_3, NULL);
  pthread_join(philosopher_4, NULL);
  pthread_join(philosopher_5, NULL);
  pthread_join(philosopher_6, NULL);
  pthread_join(philosopher_7, NULL);
  return (0);
}
