/*
** my_malloc.h for  in /home/bongol_b/ProjetsPerso/my_malloc
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Nov 22 17:11:29 2016 Berdrigue Bongolo-Beto
** Last update Tue Nov 22 17:48:01 2016 Berdrigue Bongolo-Beto
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		free(void *ptr);
void		show_alloc_mem();

#endif /* !MY_MALLOC_H_ */
