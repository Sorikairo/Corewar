/*
** load_champion.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr  5 16:21:21 2014 Laurent Fourrier
** Last update Sun Apr 13 17:10:05 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "arena.h"
#include "utils.h"

void		put_invalid_error(char *file)
{
  write_str(g_fstdout, "Error: file ");
  write_str(g_fstdout, file);
  write_str(g_fstdout, " is not a valid .cor file\n");
  flush_file(g_fstdout);
  exit(0);
}

void		add_champion(t_arena *arena, char *name, int offset)
{
  t_champion	*champ;
  t_process	*champ_proc;

  champ = xmalloc(sizeof(t_champion));
  champ_proc = xmalloc(sizeof(t_process));
  init_champion(champ);
  champ->name = utl_strcpy(name);
  champ->id = arena->last_id;
  arena->last_id++;
  init_process(champ_proc);
  champ_proc->pc = offset;
  champ_proc->reg[0] = champ->id;
  arena->champions = tl_add_elem(arena->champions, champ);
  arena->processes = tl_add_elem(arena->processes, champ_proc);
}

int		load_champion(t_arena *arena, t_file *file,
			      char *path, int offset)
{
  int		it;
  t_header	header;

  header = read_champion_header(file);
  if (!header.valid)
    {
      put_invalid_error(path);
      close_file(file);
      return (-1);
    }
  it = 0;
  while (it < header.size)
    arena->memory[(offset + it++) % MEM_SIZE] = read_char(file);
  add_champion(arena, header.name, offset);
  close_file(file);
  return (0);
}
