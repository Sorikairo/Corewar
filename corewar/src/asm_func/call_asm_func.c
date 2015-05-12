/*
** call_asm_func.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 01:41:22 2014 Laurent Fourrier
** Last update Sun Apr 13 12:38:09 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "arena.h"
#include "command.h"
#include "champion.h"
#include "asm_func.h"

void		call_asm_func(t_arena *arena, t_process *caller)
{
  t_command	command;
  t_asm_func	func;

  command = cmd_next(arena, caller);
  func = get_asm_func(command.info.code);
  if (func.func)
    func.func(arena, caller, &command);
}
