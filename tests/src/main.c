/*
** main.c for  in /home/bongol_b/ProjetsPerso/my_malloc
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Nov 22 17:29:12 2016 Berdrigue Bongolo-Beto
** Last update Tue Nov 22 18:00:54 2016 Berdrigue Bongolo-Beto
*/

#include <string.h>
#include <stdio.h>
#include "my_malloc.h"

int		main()
{
  char		*s;

  printf("Start\n");
  s = malloc(sizeof(*s) * 10);
  if (s == NULL)
    return (printf("s null\n"), 1);

  strcpy(s, "berdrigue");
  printf("%s\n", s);
  return (0);
}
