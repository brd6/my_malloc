##
## Makefile for  in /home/bongol_b/ProjetsPerso/my_malloc
## 
## Made by Berdrigue Bongolo-Beto
## Login   <bongol_b@epitech.net>
## 
## Started on  Tue Nov 22 17:02:06 2016 Berdrigue Bongolo-Beto
## Last update Tue Nov 22 17:46:50 2016 Berdrigue Bongolo-Beto
##

CC		= 	gcc -g3

RM		= 	rm -f

NAME		=	libmy_malloc.so

ROOT_DIRECTORY	=	src

SRCS		= 	$(ROOT_DIRECTORY)/malloc.c \
			$(ROOT_DIRECTORY)/realloc.c \
			$(ROOT_DIRECTORY)/free.c \
			$(ROOT_DIRECTORY)/show_alloc_mem.c \

OBJS		= 	$(SRCS:.c=.o)

#CFLAGS		+=	-W -Wall -Wextra -Werror

CFLAGS		+=	-I./include/ -fPIC

LDFLAGS 	+=	-shared

all: $(NAME)

tests:
	@sh ./tests/runtests.sh

$(NAME): $(OBJS)
	@$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, re, all, fclean tests
