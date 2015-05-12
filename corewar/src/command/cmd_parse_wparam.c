/*
** cmd_parse_wparam.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr 12 10:34:05 2014 Laurent Fourrier
** Last update Sun Apr 13 14:28:31 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "utils.h"
#include "arena.h"
#include "command.h"
#include "champion.h"
#include "op.h"

int		cmd_parse_wparam_arg(t_arena *arena, t_cmd_args *args,
				     char *buf, int pc)
{
  if (args->type == T_REG)
    {
      args->u_value.idx = buf[0];
      return (1);
    }
  else if (args->type == T_DIR)
    {
      args->u_value.nbr = byte_toint_be(buf);
      return (4);
    }
  else if (args->type == T_IND)
    {
      args->u_value.addr = byte_toshort_be(buf);
      return (2);
    }
  return (0);
}

t_command	cmd_parse_wparam(t_arena *arena, t_process *process, int size)
{
  char		*buf;
  int		it;
  int		buf_it;
  t_command	rtn;

  rtn.size = size;
  buf = get_memory_data(arena, process->pc, size);
  process->pc += size;
  rtn.info = get_op_info(buf[0]);
  it = 0;
  buf_it = 2;
  while (it < 4)
    {
      rtn.args[it] = cmd_prepare_arg(buf[1], it);
      buf_it += cmd_parse_wparam_arg(arena, &rtn.args[it], buf + buf_it,
				     process->pc);
      it++;
    }
  free(buf);
  return (rtn);
}
