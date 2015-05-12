/*
** command.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 11 22:14:43 2014 Laurent Fourrier
** Last update Sun Apr 13 04:52:42 2014 Laurent Fourrier
*/

#ifndef COMMAND_H_
# define COMMAND_H_

# include "arena.h"
# include "champion.h"

typedef struct	s_cmd_args
{
  int		type;
  union
  {
    short	addr;
    int		nbr;
    int		idx;
  }		u_value;
}		t_cmd_args;

typedef struct	s_command
{
  int		size;
  op_t		info;
  t_cmd_args	args[4];
}		t_command;

/*
** Main function
*/
t_command	cmd_next(t_arena *arena, t_process *process);

/*
** Sub functions
*/
char		cmd_has_parambyte(char opcode);
int		cmd_get_size(char parambyte);
t_command	cmd_parse_wparam(t_arena *arena, t_process *process, int size);
t_command	cmd_parse_woparam(t_arena *arena, t_process *process);

/*
** Sub sub functions (wtf funception)
*/
t_cmd_args	cmd_prepare_arg(char parambyte, int arg_nbr);

#endif
