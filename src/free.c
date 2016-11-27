/*
** free.c for  in /home/bongol_b/ProjetsPerso/my_malloc
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Nov 22 17:32:19 2016 Berdrigue Bongolo-Beto
** Last update Sun Nov 27 17:36:44 2016 Berdrigue Bongolo-Beto
*/

#include <stdio.h>
#include <unistd.h>

#include "my_malloc.h"

void		free(void *ptr)
{
  t_header_data	*block;

  if (ptr == NULL || ptr > sbrk(0))
    return ;
  block = ptr - HEADER_DATA_SIZE;
  block->is_used = 0;
}
