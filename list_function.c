/*
** list_function.c for  in /home/steven/rendu/PSU_2015_philo
**
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
**
** Started on  Thu Mar  3 14:17:09 2016 Steven Loo Fat
** Last update Sun Mar 13 12:33:44 2016 Karmes Lionel
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "extern.h"
#include "philo.h"

void	philo_is_not_null(t_philo *new, t_philo *philo, int i)
{
  new->id = i;
  new->left = philo->left;
  new->left->right = new;
  new->right = philo;
  philo->left = new;
}

t_philo		*create_list(t_philo *philo, int how_many)
{
  int		i;
  t_philo      	*new;

  i = 0;
  new = philo;
  if (how_many == 0)
    {
      printf("Error: value 0 are forbiden\n");
      return (NULL);
    }
  while (i != how_many)
    {
      if ((new = malloc(sizeof(t_philo))) == NULL)
	{
	  printf("Error: malloc in create_liste function failed\n");
	  return (NULL);
	}
      if (philo == NULL)
	philo = philo_is_null(new, i);
      else
	philo_is_not_null(new, philo, i);
      i++;
    }
  return (philo);
}

t_philo		*feed_list(t_philo *philo, int eating)
{
  t_philo	*tmp;
  int		do_while;
  int		*finished;

  tmp = philo;
  do_while = 1;
  if (!(finished = malloc(sizeof(int))))
    return (NULL);
  *finished = 0;
  while (do_while || tmp != philo)
    {
      do_while = 0;
      tmp->finished = finished;
      tmp->eating = eating;
      tmp->chopstick_left = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
      tmp = tmp->right;
    }
  return (philo);
}

void		display_list(t_philo *philo)
{
  t_philo	*tmp;
  int		do_while;

  tmp = philo;
  do_while = 1;
  while (do_while || tmp != philo)
    {
      do_while = 0;
      tmp = tmp->right;
    }
}

void		freelist(t_philo *philo)
{
  t_philo	*tmp;
  t_philo	*tmp2;
  int		do_while;

  do_while = 1;
  tmp = philo;
  free(philo->finished);
  while (do_while || tmp != philo)
    {
      do_while = 0;
      tmp2 = tmp;
      tmp = tmp->right;
      free(tmp2);
    }
}
