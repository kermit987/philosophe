/*
** check_function.c for  in /home/steven/rendu/PSU_2015_philo
**
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
**
** Started on  Wed Mar  2 18:49:12 2016 Steven Loo Fat
** Last update Sun Mar 13 12:25:05 2016 Steven Loo Fat
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "philo.h"

t_philo	*philo_is_null(t_philo *new, int i)
{
  new->id = i;
  new->left = new;
  new->right = new;
  return (new);
}

int	check_right_value(int i, char **argument)
{
  if (isnumber(argument[i + 1]) ==  0)
    return (atoi(argument[i + 1]));
  return (-1);
}

int	check_enought_value(int nb_argument)
{
  if (nb_argument == 1)
    {
      printf("Error: missing argument\n");
      return (-1);
    }
  if (nb_argument != 5)
    {
      printf("Error: invalid define valued\n");
      return (-1);
    }
  return (0);
}

int	check_present_flags(int nb, char **argument)
{
  int	i;
  int	p;
  int	e;

  i = 0;
  p = 0;
  e = 0;
  while (i != nb)
    {
      if (strcmp(argument[i], "-p"))
	p = 1;
      else if (strcmp(argument[i], "-e"))
	e = 1;
      i++;
    }
  if (p == 0 || e == 0)
    {
      printf("Error: missing operand -p or -e\n");
      return (-1);
    }
  return (0);
}

int		check_eat_value(t_philo *philo)
{
  int		while_do;
  t_philo	*tmp;

  while_do = 0;
  tmp = philo;
  while (while_do == 0 && tmp != philo)
    {
      while_do = 1;
      if (tmp->eating == 0)
	return (1);
      tmp = tmp->right;
    }
  return (0);
}
