##
## Makefile for  in /home/steven/rendu/PSU_2015_philo
## 
## Made by Steven Loo Fat
## Login   <loofat_s@epitech.net>
## 
## Started on  Mon Feb 29 10:19:53 2016 Steven Loo Fat
## Last update Sun Mar 13 12:44:57 2016 Karmes Lionel
##

CC	= gcc

RM	= rm -f

SRCS	= main.c \
	  multi_philo.c \
	  init.c \
	  list_function.c \
	  check_function.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I./include

LDFLAGS	= -L. -lriceferee -lpthread


all:	$(NAME)

$(NAME): $(OBJS)
	 @printf "\033[032m --- COMPILING ---\033[0m\n"
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	@printf "\033[032m --- CLEAN ---\033[0m\n"
	$(RM) $(OBJS)

fclean: clean
	@printf "\033[032m --- FCLEAN ---\033[0m\n"
	$(RM) $(NAME)

re: fclean all
	@printf "\033[032m --- RE DONE---\033[0m\n"

.PHONY: all clean fclean re
