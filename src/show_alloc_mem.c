/*
** show_alloc_mem.c for  in /home/bongol_b/ProjetsPerso/my_malloc
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Nov 22 17:33:28 2016 Berdrigue Bongolo-Beto
** Last update Sat Nov 26 22:54:12 2016 Berdrigue Bongolo-Beto
*/

#include "my_malloc.h"

void		show_alloc_mem()
{
  t_header_data *tmp;

  printf("break : %p\n", sbrk(0));
  tmp = used_lists;
  while (tmp->next != NULL)
    tmp = tmp->next;
  while (tmp != NULL)
    {
      if (!tmp->is_use)
	continue;
      printf("%p - %p : %lu bytes\n", ((char *)tmp + HEADER_DATA_SIZE),
	     ((char *)tmp + HEADER_DATA_SIZE) + tmp->size, tmp->size);
      tmp = tmp->prev;
    }
}
