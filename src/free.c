/*
** free.c for  in /home/bongol_b/ProjetsPerso/my_malloc
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Nov 22 17:32:19 2016 Berdrigue Bongolo-Beto
** Last update Sun Nov 27 00:31:00 2016 Berdrigue Bongolo-Beto
*/

#include <unistd.h>
#include "my_malloc.h"

static void	add_block_to_free_lists(t_header_data *block)
{
  int		correct_size;
  int		i;

  correct_size = ALIGN(block->size + HEADER_DATA_SIZE);
  i = get_class_size(correct_size);
  if (i == -1)
    i = CLASS_SIZE - 1;
  block->is_use = 0;
  block->size = 0;
  block->prev = NULL;
  block->next = &free_lists[i];
  free_lists[i].prev = block;
  free_lists[i] = *block;
}

void		free(void *ptr)
{
  t_header_data	*block;

  if (ptr == NULL || ptr > sbrk(0))
    return ;
  block = ptr - HEADER_DATA_SIZE;
  add_block_to_free_lists(block);
}
