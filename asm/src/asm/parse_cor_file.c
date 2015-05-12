/*
** parse_cor_file.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 29 03:36:29 2014 Laurent Fourrier
** Last update Sat Apr  5 13:57:53 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tio.h>
#include "asm.h"
#include "reader.h"
#include "checker.h"

t_parseinfo	parse_cor_file(t_file *input)
{
  t_parseinfo	rtn;

  rtn.cor_file = read_cor_file(input);
  rtn.label_list = generate_label_list(rtn.cor_file);
  if (transform_parameters(rtn.cor_file, rtn.label_list) == -1 ||
      check_cor_file(rtn.cor_file) == -1)
    {
      free_cor_file(rtn.cor_file);
      rtn.cor_file = NULL;
    }
  return (rtn);
}
