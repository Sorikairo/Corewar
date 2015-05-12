/*
** update_game_state.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 12:51:22 2014 Laurent Fourrier
** Last update Sun Apr 13 12:58:48 2014 Laurent Fourrier
*/

#include "champion.h"
#include "arena.h"

t_list		*iterate_champion_state(t_list *list, t_list *cur, void *param)
{
  char		*alive;
  t_champion	*champ;

  alive = param;
  champ = cur->data;
  if (champ->alive)
    *alive += 1;
  return (list);
}

void		update_game_state(t_arena *arena)
{
  char		alive;

  alive = 0;
  arena->champions = tl_iterate(arena->champions, &alive,
				&iterate_champion_state);
  arena->playing = (alive > 1);
}
