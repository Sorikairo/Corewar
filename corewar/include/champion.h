/*
** champion.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr  5 16:05:55 2014 Laurent Fourrier
** Last update Sun Apr 13 15:58:15 2014 Laurent Fourrier
*/

#ifndef CHAMPION_H_
# define CHAMPION_H_

# include <tio.h>
# include "op.h"

# define HEADER_MAGIC	0x5642CAFE

typedef struct	s_champion
{
  char		alive;
  char		*name;
  int		id;
  int		life;
}		t_champion;

typedef struct	s_header
{
  char		valid;
  char		name[PROG_NAME_LENGTH+1];
  char		comment[COMMENT_LENGTH+1];
  int		size;
}		t_header;

typedef struct	s_process
{
  int		pc;
  int		carry;
  int		cycles_left;
  int		reg[REG_NUMBER];
  t_champion	*parent;
}		t_process;

void		init_process(t_process *proc);
void		init_champion(t_champion *champ);

t_header	read_champion_header(t_file *file);

#endif
