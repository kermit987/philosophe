/*
** philo.h for  in /home/steven/rendu/PSU_2015_philo
**
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
**
** Started on  Wed Mar  2 16:36:56 2016 Steven Loo Fat
** Last update Sun Mar 13 12:43:02 2016 Karmes Lionel
*/

#ifndef PHILO_H_
# define PHILO_H_

# include "errno.h"

typedef struct			s_philo
{
  int				*finished;
  int				id;
  pthread_t			id_thread;
  unsigned int			eating;
  pthread_mutex_t		chopstick_left;
  struct s_philo	        *left;
  struct s_philo		*right;
}				t_philo;

int				isnumber(char *);
int				check_right_value(int , char **);
int				check_enought_value(int);
t_philo				*which_flags(t_philo *, char **, int);
t_philo				*parsing(int, char **);
void				only_one(unsigned int);
int				init(int, char **);
void				multi_philo(t_philo *);
int				check_present_flags(int, char **);
t_philo				*feed_list(t_philo *, int);
t_philo				*create_list(t_philo *, int);
t_philo				*philo_is_null(t_philo *, int);
void				philo_is_not_null(t_philo *, t_philo *, int);
t_philo				*create_list(t_philo *, int);
void				display_list(t_philo *);
int				check_eat_value(t_philo *);
void				freelist(t_philo *);
pthread_mutex_t			*routine_next(pthread_mutex_t *,
					      pthread_mutex_t *, t_philo *);

#endif /* !PHILO_H_ */
