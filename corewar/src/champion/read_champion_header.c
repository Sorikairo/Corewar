/*
** read_champion_header.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Apr  7 13:37:31 2014 Laurent Fourrier
** Last update Sun Apr 13 16:06:26 2014 Laurent Fourrier
*/

#include "champion.h"
#include "utils.h"

t_header	read_champion_header(t_file *file)
{
  int		magic;
  t_header	rtn;
  
  read_data_be(file, &magic, 4);
  rtn.valid = (magic == COREWAR_EXEC_MAGIC);
  if (!rtn.valid)
    return (rtn);
  read_data(file, rtn.name, PROG_NAME_LENGTH);
  rtn.name[PROG_NAME_LENGTH] = 0;
  read_data_be(file, &rtn.size, 4);
  read_data(file, rtn.comment, COMMENT_LENGTH);
  rtn.name[COMMENT_LENGTH] = 0;
  return (rtn);
}
