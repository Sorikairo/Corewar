/*
** labelname_is_valid.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 29 03:00:27 2014 Laurent Fourrier
** Last update Sat Mar 29 03:01:40 2014 Laurent Fourrier
*/

#include "op.h"

char		labelchar_is_valid(char c, char *valid_chars)
{
  while (*valid_chars)
    {
      if (c == *valid_chars++)
	return (1);
    }
  return (0);
}

char		labelname_is_valid(char *name)
{
  while (*name)
    {
      if (!labelchar_is_valid(*name++, LABEL_CHARS))
	return (0);
    }
  return (1);
}
