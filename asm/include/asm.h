/*
** asm.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 29 03:19:49 2014 Laurent Fourrier
** Last update Thu Apr  3 10:38:17 2014 Laurent Fourrier
*/

#ifndef ASM_H_
# define ASM_H_

# include <tio.h>
# include "reader.h"
# include "checker.h"

typedef struct	s_parseinfo
{
  t_label	*label_list;
  t_cor_file	*cor_file;
}		t_parseinfo;

int		assemble_cor(char *input, char *output);
int		assemble_fcor(t_file *input, t_file *output);

t_parseinfo	parse_cor_file(t_file *input);

#endif
