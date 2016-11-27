/*
** malloc.c for  in /home/bongol_b/ProjetsPerso/my_malloc
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Nov 22 17:29:35 2016 Berdrigue Bongolo-Beto
** Last update Sun Nov 27 17:37:18 2016 Berdrigue Bongolo-Beto
*/

// temp
#include <stdio.h>

#include <unistd.h>
#include <stddef.h>
#include "my_malloc.h"

t_header_data	*head_lists = NULL;

static int	init_head_lists()
{
  if ((head_lists = sbrk(ALIGN(HEADER_DATA_SIZE))) == (void *)-1)
    return (0);
  head_lists->size = 0;
  head_lists->true_size = 0;
  head_lists->next = NULL;
  head_lists->prev = NULL;
  head_lists->is_used = 1;
  return (1);
}

static void	*find_fit_block(size_t size)
{
  t_header_data	*tmp;

  tmp = head_lists;
  while (tmp->next != NULL)
    {
      if (tmp->is_used == 0 && tmp->size >= size)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

static void	add_block_to_head(t_header_data *block)
{
  block->next = head_lists;
  if (head_lists != NULL)
    head_lists->prev = block;
  head_lists = block;
}

static void	*alloc_new_block(size_t size, size_t true_size)
{
  t_header_data	*block;

  block = sbrk(0);
  if (sbrk(size) == (void *)-1)
    return (NULL);
  block->size = size;
  block->true_size = true_size;
  block->is_used = 0;
  block->next = NULL;
  block->prev = NULL;
  //
  add_block_to_head(block);
  return (block);
}

void		*malloc(size_t size)
{
  size_t	block_size;
  t_header_data	*block;

  if (size <= 0 || (head_lists == NULL && (!init_head_lists())))
    return (NULL);
  block_size = ALIGN(size + HEADER_DATA_SIZE);
  if ((block = find_fit_block(block_size)) == NULL)
    block = alloc_new_block(block_size, size);
  if (block == NULL)
    return (NULL);
  // split if possible
  block->is_used = 1;
  return ((char *)block + HEADER_DATA_SIZE);
}
