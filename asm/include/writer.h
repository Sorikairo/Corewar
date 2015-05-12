/*
** writer.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 29 10:00:58 2014 Laurent Fourrier
** Last update Sat Apr  5 13:20:53 2014 Laurent Fourrier
*/

#ifndef WRITER_H_
# define WRITER_H_

# include <tio.h>
# include "reader.h"
# include "checker.h"

/*
** Main caller
*/
void	writer_cor_file(t_file *file, t_cor_file *cor, t_label *label);

/*
** Sub callers
*/
void	writer_cor_header(t_file *file, t_cor_file *cor);
void	writer_cor_line(t_file *file, t_cor_line *line, t_label *label);
void	writer_cor_arg(t_file *file, t_cor_arg arg);

/*
** More specific functions
*/
void	writer_cor_parambyte(t_file *file, char **args);
void	writer_cor_register(t_file *file, int reg);
void	writer_cor_direct(t_file *file, int dir);
void	writer_cor_indirect(t_file *file, int ind);

#endif
