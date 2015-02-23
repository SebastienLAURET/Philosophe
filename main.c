#include <pthread.h>
#include <stdio.h>

#define TIME_S	1

pthread_mutex_t g_baguette_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_5 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_6 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_baguette_7 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;

void	*handle_philosopher_1(void *args)
{
  (void)(args);
  while (1)
    {
      printf("philosopher_1 : SLEEP\n");
      // usleep(TIME_S);
      pthread_mutex_lock(&g_lock);
      pthread_mutex_lock(&g_baguette_1);
      pthread_mutex_lock(&g_baguette_2);
      pthread_mutex_unlock(&g_lock);
      printf("philosopher_1 : EAT\n");
      //  usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_1);
      pthread_mutex_unlock(&g_baguette_2);
      printf("philosopher_1 : USLEEP\n");
      //usleep(TIME_S);
      pthread_mutex_lock(&g_baguette_1);
      printf("philosopher_1 : BRAIN\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_1);
    }
  return (NULL);
}

void	*handle_philosopher_2(void *args)
{
  (void)(args);
  while (1)
    {
      printf("philosopher_2 : USLEEP\n");
      //usleep(TIME_S);

      pthread_mutex_lock(&g_lock);
      pthread_mutex_lock(&g_baguette_2);
      pthread_mutex_lock(&g_baguette_3);
       pthread_mutex_unlock(&g_lock);
      printf("philosopher_2 : EAT\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_2);
      pthread_mutex_unlock(&g_baguette_3);
      printf("philosopher_2 : USLEEP\n");
      //usleep(TIME_S);
      pthread_mutex_lock(&g_baguette_2);
      printf("philosopher_2 : BRAIN\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_2);
    }
  return (NULL);
}

void	*handle_philosopher_3(void *args)
{
  (void)(args);
  while (1)
    {
       printf("philosopher_3 : USLEEP\n");
       //usleep(TIME_S);

      pthread_mutex_lock(&g_lock);
      pthread_mutex_lock(&g_baguette_3);
      pthread_mutex_lock(&g_baguette_4);
      pthread_mutex_unlock(&g_lock);
      printf("philosopher_3 : EAT\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_3);
      pthread_mutex_unlock(&g_baguette_4);

      printf("philosopher_3 : USLEEP\n");
      // usleep(TIME_S);

      pthread_mutex_lock(&g_baguette_3);
      printf("philosopher_3 : BRAIN\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_3);
    }
  return (NULL);
}

void	*handle_philosopher_4(void *args)
{
  (void)(args);
  while (1)
    {
       printf("philosopher_4 : USLEEP\n");
       //usleep(TIME_S);
      pthread_mutex_lock(&g_lock);
      pthread_mutex_lock(&g_baguette_4);
      pthread_mutex_lock(&g_baguette_5);
      pthread_mutex_unlock(&g_lock);
      printf("philosopher_4 : EAT\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_4);
      pthread_mutex_unlock(&g_baguette_5);

      printf("philosopher_4 : USLEEP\n");
      //usleep(TIME_S);

      pthread_mutex_lock(&g_baguette_4);
      printf("philosopher_4 : BRAIN\n");
      // usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_4);
    }
  return (NULL);
}

void	*handle_philosopher_5(void *args)
{
  (void)(args);
  while (1)
    {
       printf("philosopher_5 : USLEEP\n");
       //usleep(TIME_S);
      pthread_mutex_lock(&g_lock);
      pthread_mutex_lock(&g_baguette_5);
      pthread_mutex_lock(&g_baguette_6);
      pthread_mutex_unlock(&g_lock);
      printf("philosopher_5 : EAT\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_5);
      pthread_mutex_unlock(&g_baguette_6);

      printf("philosopher_5 : USLEEP\n");
      //usleep(TIME_S);

      pthread_mutex_lock(&g_baguette_5);
      printf("philosopher_5 : BRAIN\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_5);
    }
  return (NULL);
}

void	*handle_philosopher_6(void *args)
{
  (void)(args);
  while (1)
    {
       printf("philosopher_6 : USLEEP\n");
       //usleep(TIME_S);
      pthread_mutex_lock(&g_lock);
      pthread_mutex_lock(&g_baguette_6);
      pthread_mutex_lock(&g_baguette_7);
      pthread_mutex_unlock(&g_lock);
      printf("philosopher_6 : EAT\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_6);
      pthread_mutex_unlock(&g_baguette_7);
      printf("philosopher_6 : USLEEP\n");
      //usleep(TIME_S);
      pthread_mutex_lock(&g_baguette_6);
      printf("philosopher_6 : BRAIN\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_6);
    }
  return (NULL);
}

void	*handle_philosopher_7(void *args)
{
  (void)(args);
  while (1)
    {
       printf("philosopher_7 : USLEEP\n");
       //usleep(TIME_S);
      pthread_mutex_lock(&g_lock);
      pthread_mutex_lock(&g_baguette_7);
      pthread_mutex_lock(&g_baguette_1);
      pthread_mutex_unlock(&g_lock);
      printf("philosopher_7 : EAT\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_7);
      pthread_mutex_unlock(&g_baguette_1);
      printf("philosopher_7 : USLEEP\n");
      // usleep(TIME_S);
      pthread_mutex_lock(&g_baguette_7);
      printf("philosopher_7 : BRAIN\n");
      //usleep(TIME_S);
      pthread_mutex_unlock(&g_baguette_7);
    }
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
