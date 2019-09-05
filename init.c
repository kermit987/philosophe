/*
** init.c for  in /home/steven/rendu/PSU_2015_philo
**
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
**
** Started on  Wed Mar  2 22:25:47 2016 Steven Loo Fat
** Last update Sun Mar 13 12:23:20 2016 Steven Loo Fat
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "philo.h"
#include "extern.h"

int		init(int nb_argument, char **argument)
{
  t_philo	*philo;

  if ((philo = parsing(nb_argument, argument)) == NULL)
    return (-1);
  if (strcmp(argument[2], "1") == 0)
    {
      printf("1 philo is impossible, it's prohibited to cut one ");
      printf("chopstick in 2 chopstick\n");
      return (-1);
    }
  multi_philo(philo);
  freelist(philo);
  return (0);
}
