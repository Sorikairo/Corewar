/*
** live.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 20:56:54 2014 Laurent Fourrier
** Last update Sun Apr 13 15:00:49 2014 Laurent Fourrier
*/

#include <tio.h>
#include "arena.h"
#include "command.h"
#include "champion.h"
#include "op.h"

void		asm_live(t_arena *arena, t_process *caller, t_command *cmd)
{
  t_champion	*champ;

  champ = get_champion_by_id(arena, cmd->args[0].u_value.nbr);
  if (champ)
    {
      write_str(g_fstdout, champ->name);
      write_str(g_fstdout, " is living!\n");
      flush_file(g_fstdout);
      champ->life = 0;
    }
  arena->live_count++;
  if (arena->live_count >= NBR_LIVE)
    {
      arena->live_count = 0;
      arena->cycle_to_die -= CYCLE_DELTA;
    }
}
