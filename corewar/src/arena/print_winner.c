/*
** print_winner.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 14:51:35 2014 Laurent Fourrier
** Last update Sun Apr 13 14:57:10 2014 Laurent Fourrier
*/

#include "arena.h"

t_list		*iterate_winner(t_list *list, t_list *cur, void *param)
{
  t_champion	*champ;

  champ = param;
  if (champ->alive)
    param = champ->name;
  return (list);
}

void	print_winner(t_arena *arena)
{
  char	*winner;

  winner = "Nobody";
  arena->champions = tl_iterate(arena->champions, &winner, &iterate_winner);
  write_str(g_fstdout, winner);
  write_str(g_fstdout, " is the winner!\n");
  flush_file(g_fstdout);
}
