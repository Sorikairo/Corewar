/*
** asm_func.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 16:43:35 2014 Laurent Fourrier
** Last update Sun Apr 13 06:17:19 2014 Laurent Fourrier
*/

#ifndef ASM_FUNC_H_
# define ASM_FUNC_H_

# include "command.h"
# include "arena.h"
# include "op.h"

typedef void	(*t_asmfunc)(t_arena *arena, t_process *caller, t_command *cmd);

typedef struct	s_asm_func
{
  char		opcode;
  t_asmfunc	func;
}		t_asm_func;

void		call_asm_func(t_arena *arena, t_process *caller);
t_asm_func	get_asm_func(char opcode);

/*
** Implement asm functions here...
*/
void		asm_live(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_ld(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_st(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_add(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_sub(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_and(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_or(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_xor(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_zjmp(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_ldi(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_sti(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_fork(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_lld(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_lldi(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_lfork(t_arena *arena, t_process *caller, t_command *cmd);
void		asm_aff(t_arena *arena, t_process *caller, t_command *cmd);

#endif
