/*
** is_big_endian.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 21:21:57 2014 Laurent Fourrier
** Last update Tue Apr  8 21:22:23 2014 Laurent Fourrier
*/

char	is_big_endian()
{
  char	*bytes;
  short	checker;

  checker = 1;
  bytes = (char*)&checker;
  return (bytes[1]);
}
