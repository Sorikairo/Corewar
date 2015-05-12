/*
** reader.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 14:10:08 2014 Laurent Fourrier
** Last update Fri Apr  4 16:38:27 2014 Laurent Fourrier
*/

#ifndef READER_H_
# define READER_H_

# include <tio.h>

# define T_ERR		8

# define ERR_UNKNW	0
# define ERR_REG_NAN	1
# define ERR_REG_OUT	2
# define ERR_LABEL	3
# define ERR_DIR_NAN	4
# define ERR_IND_NAN	5

typedef struct		s_cor_arg
{
  char			type;
  int			val;
}			t_cor_arg;

typedef struct		s_cor_line
{
  char			*label;
  char			*instruction;
  char			**args;
  int			nbr;
  int			mempos;
  t_cor_arg		*p_args;
  struct s_cor_line	*next;
}			t_cor_line;

typedef struct		s_cor_file
{
  char			*name;
  char			*comment;
  int			file_size;
  t_cor_line		*first_line;
}			t_cor_file;

/*
** Read functions
*/
t_cor_file	*read_cor_file(t_file *file);
int		read_cor_line(t_file *file, t_cor_file *cor, int line_nbr);
int		read_cor_instruct(char *line, t_cor_file *cor, int line_nbr);

/*
** Structure management functions
*/
t_cor_file	*new_cor_file();
void		free_cor_file(t_cor_file *file);
t_cor_line	*new_cor_line();
void		free_cor_line(t_cor_line *line);

#endif
