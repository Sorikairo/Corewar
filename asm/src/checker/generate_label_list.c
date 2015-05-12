/*
** generate_label_list.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 15:53:24 2014 Laurent Fourrier
** Last update Sat Apr  5 15:21:33 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tutils.h>
#include "reader.h"
#include "checker.h"
#include "op.h"

int		get_line_memsize(t_cor_line *line)
{
  int		it;
  int		rtn;
  op_t		op;

  it = 0;
  rtn = 1;
  if (line->instruction && line->instruction[0])
    {
      op = get_op(line->instruction);
      rtn += line_has_parambyte(op.code);
      while (line->args[it] != NULL)
	{
	  if (line->args[it][0] == 'r')
	    rtn += 1;
	  else if (line->args[it][0] == DIRECT_CHAR)
	    rtn += DIR_SIZE;
	  else
	    rtn += IND_SIZE;
	  it++;
	}
    }
  return (rtn);
}

t_label		*generate_label_list(t_cor_file *file)
{
  int		mem_pos;
  t_label	*rtn;
  t_cor_line	*line;

  rtn = NULL;
  mem_pos = 0;
  line = file->first_line;
  while (line)
    {
      if (line->label && utl_strcmp(line->label, ""))
	{
	  if (label_exists(rtn, line->label) ||
	      !labelname_is_valid(line->label))
	    {
	      destroy_label_list(rtn);
	      return (NULL);
	    }
	  rtn = label_list_append(rtn, line->label, mem_pos);
	}
      mem_pos += get_line_memsize(line);
      line->mempos = mem_pos;
      line = line->next;
    }
  file->file_size = mem_pos;
  return (rtn);
}
