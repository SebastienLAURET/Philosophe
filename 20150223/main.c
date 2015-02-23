/*
** main.c for philosophes in /home/rosain_f/rendu/PSU_2014_philo
** 
** Made by Francois Rosain
** Login   <rosain_f@epitech.net>
** 
** Started on  Sun Feb 22 08:32:03 2015 Francois Rosain
** Last update Mon Feb 23 16:23:31 2015 Francois Rosain
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "philosophe.h"

# define TURN_TIME 1

extern	t_stat g_stat_philo[7];

GtkWidget	*pImage0;
GtkWidget	*pImage1;
GtkWidget	*pImage2;
GtkWidget	*pImage3;
GtkWidget	*pImage4;
GtkWidget	*pImage5;
GtkWidget	*pImage6;

void	update_images()
{
  printf("--- --- --- --- ---\n");
  if (g_stat_philo[0] == EAT)
    gtk_image_set_from_file(GTK_IMAGE(pImage0), "./images/eat.png");
  else if (g_stat_philo[0] == SLEEP)
    gtk_image_set_from_file(GTK_IMAGE(pImage0), "./images/sleep.png");
  else if (g_stat_philo[0] == THINK)
    gtk_image_set_from_file(GTK_IMAGE(pImage0), "./images/think.png");

  if (g_stat_philo[1] == EAT)
    gtk_image_set_from_file(GTK_IMAGE(pImage1), "./images/eat.png");
  else if (g_stat_philo[1] == SLEEP)
    gtk_image_set_from_file(GTK_IMAGE(pImage1), "./images/sleep.png");
  else if (g_stat_philo[1] == THINK)
    gtk_image_set_from_file(GTK_IMAGE(pImage1), "./images/think.png");

  if (g_stat_philo[2] == EAT)
    gtk_image_set_from_file(GTK_IMAGE(pImage2), "./images/eat.png");
  else if (g_stat_philo[2] == SLEEP)
    gtk_image_set_from_file(GTK_IMAGE(pImage2), "./images/sleep.png");
  else if (g_stat_philo[2] == THINK)
    gtk_image_set_from_file(GTK_IMAGE(pImage2), "./images/think.png");

  if (g_stat_philo[3] == EAT)
    gtk_image_set_from_file(GTK_IMAGE(pImage3), "./images/eat.png");
  else if (g_stat_philo[3] == SLEEP)
    gtk_image_set_from_file(GTK_IMAGE(pImage3), "./images/sleep.png");
  else if (g_stat_philo[3] == THINK)
    gtk_image_set_from_file(GTK_IMAGE(pImage3), "./images/think.png");

  if (g_stat_philo[4] == EAT)
    gtk_image_set_from_file(GTK_IMAGE(pImage4), "./images/eat.png");
  else if (g_stat_philo[4] == SLEEP)
    gtk_image_set_from_file(GTK_IMAGE(pImage4), "./images/sleep.png");
  else if (g_stat_philo[4] == THINK)
    gtk_image_set_from_file(GTK_IMAGE(pImage4), "./images/think.png");

  if (g_stat_philo[5] == EAT)
    gtk_image_set_from_file(GTK_IMAGE(pImage5), "./images/eat.png");
  else if (g_stat_philo[5] == SLEEP)
    gtk_image_set_from_file(GTK_IMAGE(pImage5), "./images/sleep.png");
  else if (g_stat_philo[5] == THINK)
    gtk_image_set_from_file(GTK_IMAGE(pImage5), "./images/think.png");

  if (g_stat_philo[6] == EAT)
    gtk_image_set_from_file(GTK_IMAGE(pImage6), "./images/eat.png");
  else if (g_stat_philo[6] == SLEEP)
    gtk_image_set_from_file(GTK_IMAGE(pImage6), "./images/sleep.png");
  else if (g_stat_philo[6] == THINK)
    gtk_image_set_from_file(GTK_IMAGE(pImage6), "./images/think.png");
}

static int	philosophes(GtkWidget *pWindow)
{
  static int	i = 0;
  if (i == 1)
    return (0);
  i = 1;
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

  g_timeout_add(500, (GSourceFunc) update_images, NULL);  

  gtk_widget_show_all(pWindow);
  gtk_main();
}

int		main(int ac, char **av)
{ 
  GtkWidget	*pWindow;
  GtkWidget	*pHBox;
  GtkWidget	*pQuitImage;
  GtkWidget	*pQuitBtn;
  GtkWidget	*pFixed;
  //
  gtk_init(&ac, &av);

  pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(pWindow), 1000, 200);
  gtk_window_set_title(GTK_WINDOW(pWindow), "Gtk - Philosophes");
  g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  /* Container horizontal (align images) */
  pHBox = gtk_hbox_new(0, 10); // spacing
  gtk_container_add(GTK_CONTAINER(pWindow), pHBox);

  /* Loading images  :  default sleep.png */
  pImage0 = gtk_image_new_from_file("./images/sleep.png");
  gtk_widget_set_size_request(pImage0, 132, 132);  
  gtk_box_pack_start(GTK_BOX(pHBox), pImage0, 0, 0, 5);
  
  pImage1 = gtk_image_new_from_file("./images/sleep.png");
  gtk_widget_set_size_request(pImage1, 132, 132);
  gtk_box_pack_start(GTK_BOX(pHBox), pImage1, 0, 0, 5);
  
  pImage2 = gtk_image_new_from_file("./images/sleep.png");
  gtk_widget_set_size_request(pImage2, 132, 132);
  gtk_box_pack_start(GTK_BOX(pHBox), pImage2, 0, 0, 5);

  pImage3 = gtk_image_new_from_file("./images/sleep.png");
  gtk_widget_set_size_request(pImage3, 132, 132);
  gtk_box_pack_start(GTK_BOX(pHBox), pImage3, 0, 0, 5);

  pImage4 = gtk_image_new_from_file("./images/sleep.png");
  gtk_widget_set_size_request(pImage4, 132, 132);
  gtk_box_pack_start(GTK_BOX(pHBox), pImage4, 0, 0, 5);

  pImage5 = gtk_image_new_from_file("./images/sleep.png");
  gtk_widget_set_size_request(pImage5, 132, 132);
  gtk_box_pack_start(GTK_BOX(pHBox), pImage5, 0, 0, 5);

  pImage6 = gtk_image_new_from_file("./images/sleep.png");
  gtk_widget_set_size_request(pImage6, 132, 132);
  gtk_box_pack_start(GTK_BOX(pHBox), pImage6, 0, 0, 5);
  philosophes(pWindow);
}
