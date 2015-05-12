/*
** cmd_parse_woparam.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr 12 16:42:33 2014 Laurent Fourrier
** Last update Sun Apr 13 06:07:27 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "utils.h"
#include "arena.h"
#include "command.h"
#include "champion.h"

t_command	cmd_parse_woparam(t_arena *arena, t_process *process)
{
  char		*buf;
  int		it;
  t_command	rtn;

  rtn.size = 5;
  buf = get_memory_data(arena, process->pc, rtn.size);
  process->pc += rtn.size;
  rtn.info = get_op_info(buf[0]);
  rtn.args[0].type = T_DIR;
  rtn.args[0].u_value.nbr = byte_toint_be(buf + 1);
  it = 1;
  while (it < 4)
    {
      rtn.args[it].type = 0;
      rtn.args[it].u_value.nbr = 0;
      it++;
    }
  free(buf);
  return (rtn);
}
