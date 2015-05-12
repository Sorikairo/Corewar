/*
** utils.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 15:59:08 2014 Laurent Fourrier
** Last update Sun Mar 30 18:57:09 2014 Laurent Fourrier
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <tio.h>

void	*xmalloc(int size);

char	*change_filext(char *filename, char *new_ext);

void	write_data_be(t_file *file, void *data, int size);

void	*short_tobyte(short data);
void	*int_tobyte(int data);

#endif
