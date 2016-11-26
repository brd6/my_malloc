/*
** malloc.c for  in /home/bongol_b/ProjetsPerso/my_malloc
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Nov 22 17:29:35 2016 Berdrigue Bongolo-Beto
** Last update Sun Nov 27 00:15:10 2016 Berdrigue Bongolo-Beto
*/

// temp
#include <stdio.h>

#include <unistd.h>
#include <stddef.h>
#include "my_malloc.h"

t_header_data	*free_lists = NULL;
t_header_data	*used_lists = NULL;

int		get_class_size(size_t size)
{
  size_t	val;
  int		i;

  val = MIN_CLASS_SIZE;
  i = 0;
  while (i < CLASS_SIZE)
    {
      if (val >= size)
	return (i);
      val *= 2;
      i++;
    }
  return (-1);
}

static int	init_free_lists()
{
  int		i;

  i = 0;
  free_lists = sbrk(HEADER_DATA_SIZE * CLASS_SIZE);
  if (free_lists == (void *)-1)
    return (0);
  while (i < CLASS_SIZE)
    {
      free_lists[i].size = 0;
      free_lists[i].next = free_lists[i].prev = &free_lists[i];
      i++;
    }
  return (1);
}

static void	*split_block(t_header_data *block, size_t size)
{
  //printf("size: %d\n", block->size);
  return (block);
}

static void	remove_from_free_lists(t_header_data *block, int class_index)
{
  if (block == NULL)
    return ;
  if (block->prev != NULL)
    block->prev->next = block->next;
  if (block->next != NULL)
    block->next->prev = block->prev;
  block->next = NULL;
  block->prev = NULL;
}

static void	*find_fit_block(size_t size)
{
  int		i;
  t_header_data	*block;

  i = get_class_size(size);
  if (i == -1)
    return (NULL);
  block = free_lists[i].next;
  remove_from_free_lists(block, i);
  /* block = split_block(block, size); */
  return (block);
}

static void	*alloc_new_block(size_t size)
{
  t_header_data	*block;
  void		*p;

  block = sbrk(0);
  p = sbrk(size);
  block->prev = NULL;
  block->next = NULL;
  block->size = 0; // size : for coalesce...
  return (block);
}

static void	add_used_block(t_header_data *block, size_t size)
{
  t_header_data	*tmp;

  block->next = NULL;
  block->prev = NULL;
  block->size = size;
  block->is_use = 1;
  if (used_lists == NULL)
    {
      used_lists = block;
      return ;
    }
  block->next = used_lists;
  used_lists->prev = block;
  used_lists = block;
}

void		*malloc(size_t size)
{
  size_t	block_size;
  t_header_data	*block;

  if (free_lists == NULL && (!init_free_lists()))
    return (NULL);
  block_size = ALIGN(size + HEADER_DATA_SIZE);
  block = find_fit_block(block_size);
  printf("find : %p\n", block);
  if (block == NULL)
    block = alloc_new_block(block_size);
  add_used_block(block, size);
  return ((char *)block + HEADER_DATA_SIZE);
}
