/*
** init_champion.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 21:13:12 2014 Laurent Fourrier
** Last update Sun Apr 13 04:37:19 2014 Laurent Fourrier
*/

#include <stddef.h>
#include "champion.h"

void	init_champion(t_champion *champ)
{
  champ->alive = 1;
  champ->name = NULL;
  champ->id = 0;
  champ->life = 0;
}
