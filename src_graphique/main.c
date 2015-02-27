/*
** main.c for philosophes in /home/rosain_f/rendu/PSU_2014_philo
**
** Made by Francois Rosain
** Login   <rosain_f@epitech.net>
**
** Started on  Sun Feb 22 08:32:03 2015 Francois Rosain
** Last update Fri Feb 27 10:37:29 2015 Francois Rosain
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "gtk/gtk.h"
#include "philosophe.h"

extern t_stat	g_stat_philo[7];
GtkWidget	*g_images[7];

void	update_g_images()
{
  int	i;

  printf("--- --- --- --- ---\n");
  i = 0;
  while (i < 7)
    {
      if (g_stat_philo[i] == EAT)
	gtk_image_set_from_file(GTK_IMAGE(g_images[i]),
				"./src_graphique/images/eat.png");
      else if (g_stat_philo[i] == SLEEP)
	gtk_image_set_from_file(GTK_IMAGE(g_images[i]),
				"./src_graphique/images/sleep.png");
      else
	gtk_image_set_from_file(GTK_IMAGE(g_images[i]),
				"./src_graphique/images/think.png");
      i++;
    }
}

static void	philosophes(GtkWidget *window)
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
  g_timeout_add(T_UPDATE, (GSourceFunc)update_g_images, NULL);
  gtk_widget_show_all(window);
  gtk_main();
}

int		main(int ac, char **av)
{
  GtkWidget	*window;
  GtkWidget	*hbox;
  int		i;

  i = 0;
  gtk_init(&ac, &av);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 1000, 200);
  gtk_window_set_title(GTK_WINDOW(window), "Gtk - Philosophes");
  g_signal_connect(G_OBJECT(window), "destroy",
		   G_CALLBACK(gtk_main_quit), NULL);
  hbox = gtk_hbox_new(0, 10);
  gtk_container_add(GTK_CONTAINER(window), hbox);
  while (i < 7)
    {
      g_images[i] = gtk_image_new_from_file("./src_graphique/images/sleep.png");
      gtk_widget_set_size_request(g_images[i], 132, 132);
      gtk_box_pack_start(GTK_BOX(hbox), g_images[i], 0, 0, 5);
      i++;
    }
  philosophes(window);
  return (0);
}
