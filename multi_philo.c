/*
** multi_philo.c for  in /home/steven/rendu/PSU_2015_philo
**
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
**
** Started on  Wed Mar  2 22:54:12 2016 Steven Loo Fat
** Last update Sun Mar 13 12:36:34 2016 Steven Loo Fat
*/

#include <stdio.h>
#include <pthread.h>
#include "philo.h"
#include "extern.h"

pthread_mutex_t			*routine_next(pthread_mutex_t *chopstick1,
					      pthread_mutex_t *chopstick2, t_philo *philo)
{
  chopstick2 = (chopstick1 == &philo->chopstick_left) ?
    &philo->right->chopstick_left : &philo->chopstick_left;
  lphilo_take_chopstick(chopstick2);
  pthread_mutex_lock(chopstick2);
  philo->eating--;
  lphilo_eat();
  return (chopstick2);
}

void			*routine(void *arg)
{
  t_philo		*philo;
  pthread_mutex_t	*chopstick1;
  pthread_mutex_t	*chopstick2;

  philo = arg;
  while (philo->eating != 0 && *philo->finished == 0)
    {
      lphilo_sleep();
      chopstick1 = (philo->id % 2) ?
	&philo->chopstick_left : &philo->right->chopstick_left;
      lphilo_take_chopstick(chopstick1);
      pthread_mutex_lock(chopstick1);
      lphilo_think();
      chopstick2 = routine_next(chopstick1, chopstick2, philo);
      lphilo_release_chopstick(chopstick1);
      pthread_mutex_unlock(chopstick1);
      lphilo_release_chopstick(chopstick2);
      pthread_mutex_unlock(chopstick2);
    }
  *philo->finished = 1;
  return NULL;
}

void			multi_philo(t_philo *philo)
{
  int			do_while;
  t_philo		*tmp;

  do_while = 1;
  tmp = philo;
  while (do_while || philo != tmp)
    {
      do_while = 0;
      if (pthread_create(&tmp->id_thread, NULL, &routine, tmp))
	return ((void)fprintf(stderr, "error : pthread_create()\n"));
      tmp = tmp->right;
    }
  do_while = 1;
  while (do_while || philo != tmp)
    {
      do_while = 0;
      if (pthread_join(tmp->id_thread, NULL))
      	return ((void)fprintf(stderr, "error : pthread_join()\n"));
      tmp = tmp->right;
    }
}
