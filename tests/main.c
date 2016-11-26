/*
** main.c for  in /home/bongol_b/ProjetsPerso/my_malloc/tests
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Nov 24 22:21:22 2016 Berdrigue Bongolo-Beto
** Last update Sat Nov 26 18:47:15 2016 Berdrigue Bongolo-Beto
*/

#include <unistd.h>

int		main()
{
  char *s = malloc(12);

  strcpy(s, "abc");
  return (0);
}
