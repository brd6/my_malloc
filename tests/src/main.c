/*
** main.c for  in /home/bongol_b/ProjetsPerso/my_malloc
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Nov 22 17:29:12 2016 Berdrigue Bongolo-Beto
** Last update Sun Nov 27 17:44:58 2016 Berdrigue Bongolo-Beto
*/

#include <string.h>
#include <stdio.h>
#include "my_malloc.h"

int		main()
{
  char		*s;
  char		*p;

  printf("Start\n");
  s = malloc(sizeof(*s) * 10);
  p = malloc(sizeof(*s) * 10);
  if (s == NULL)
    return (printf("s null\n"), 1);
  strcpy(s,"test !");
  printf("%s\n", s);
  free(s);
  free(p);
  p = malloc(sizeof(*s) * 11);
  free(p);
  p = malloc(sizeof(*s) * 11);
  //free(p);
  p = malloc(sizeof(*s) * 11);
  //free(p);
  p = malloc(sizeof(*s) * 110);
  //free(p);
  /* show_alloc_mem(); */
  //free(s);
  show_alloc_mem();
  return (0);
}
