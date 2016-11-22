##
## Makefile for  in /home/bongol_b/ProjetsPerso/my_malloc
## 
## Made by Berdrigue Bongolo-Beto
## Login   <bongol_b@epitech.net>
## 
## Started on  Tue Nov 22 17:02:06 2016 Berdrigue Bongolo-Beto
## Last update Tue Nov 22 18:13:39 2016 Berdrigue Bongolo-Beto
##

CC		= 	gcc -g3

RM		= 	rm -f

NAME		=	test

ROOT_DIRECTORY	=	src

SRCS		= 	$(ROOT_DIRECTORY)/main.c \

OBJS		= 	$(SRCS:.c=.o)

#CFLAGS		+=	-W -Wall -Wextra -Werror

CFLAGS		+=	-I./../include/

LDFLAGS 	+=	-L../ -lmy_malloc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, re, all, fclean
