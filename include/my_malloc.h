/*
** my_malloc.h for  in /home/bongol_b/ProjetsPerso/my_malloc
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Nov 22 17:11:29 2016 Berdrigue Bongolo-Beto
** Last update Sat Nov 26 23:43:53 2016 Berdrigue Bongolo-Beto
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

# include <stddef.h>

# define ALIGNMENT		sizeof(size_t)
# define ALIGN(size)		(((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))
# define CLASS_SIZE		10
# define MIN_CLASS_SIZE		64
# define HEADER_DATA_SIZE	sizeof(t_header_data)

typedef struct		s_header_data
{
  size_t		size;
  int			is_use;
  struct s_header_data	*prev;
  struct s_header_data	*next;
}			t_header_data;

extern t_header_data	*free_lists;
extern t_header_data	*used_lists;

void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		free(void *ptr);
void		show_alloc_mem();
int		get_class_size(size_t size);

#endif /* !MY_MALLOC_H_ */
