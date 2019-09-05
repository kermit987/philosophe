/*
** main.c for  in /home/steven/rendu/PSU_2015_philo
**
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
**
** Started on  Mon Feb 29 10:25:54 2016 Steven Loo Fat
** Last update Sun Mar 13 12:41:51 2016 Karmes Lionel
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"
#include "philo.h"

int	isnumber(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!isdigit(str[i]))
	{
	  printf("Error: Must take a number as value\n");
	  return (-1);
	}
      i++;
    }
  return (0);
}

t_philo	*which_flags(t_philo *philo, char **argument, int i)
{
  int	nb;

  if (strcmp(argument[i], "-p") == 0)
    {
      if ((nb = check_right_value(i, argument)) == -1)
	return (NULL);
      philo = create_list(philo, nb);
    }
  else if (strcmp(argument[i], "-e") == 0)
    {
      if ((nb = check_right_value(i, argument)) == -1)
	return (NULL);
      philo = feed_list(philo, nb);
    }
  else
    {
      printf("Invalid argument\n");
      return (NULL);
    }
  return (philo);
}

t_philo 	*parsing(int nb_argument, char **argument)
{
  int		i;
  t_philo	*philo;

  i = 1;
  philo = NULL;
  if ((check_enought_value(nb_argument)) == -1)
    return (NULL);
  if ((check_present_flags(nb_argument, argument)) == -1)
    return (NULL);
  while (i != nb_argument)
    {
      if ((philo = which_flags(philo, argument, i)) == NULL)
      	return (NULL);
      i += 2;
    }
  display_list(philo);
  return (philo);
}

int	main(int argc, char *argv[])
{
  RCFStartup(argc, argv);
  if ((init(argc, argv)) == -1)
    return (-1);
  RCFCleanup();
  return (0);
}
