/*
** checker.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 15:41:14 2014 Laurent Fourrier
** Last update Sat Apr  5 14:10:24 2014 Laurent Fourrier
*/

#ifndef CHECKER_H_
# define CHECKER_H_

# include "reader.h"
# include "op.h"

typedef struct		s_label
{
  char			*name;
  int			mem_pos;
  struct s_label	*next;
}			t_label;

/*
** Label list functions
*/
char			label_exists(t_label *list, char *name);
char			labelname_is_valid(char *name);
t_label			*generate_label_list(t_cor_file *file);
t_label			*label_list_append(t_label *list, char *name,
					   int mem_pos);
void			destroy_label_list(t_label *list);

/*
** Parameters functions
*/
int			transform_parameters(t_cor_file *file, t_label *label);
t_cor_arg		to_cor_arg(char *arg, int mempos, t_label *label);

/*
** Check functions
*/
int			check_cor_file(t_cor_file *file);
int			check_cor_header(t_cor_file *file);
int			check_cor_line(t_cor_line *line);

/*
** Check utils functions
*/
op_t			get_op(char *mnemonic);
char			line_has_parambyte(char opcode);
int			is_valid_mnemonic(char *mnemonic);
int			is_valid_args_nbr(char *mnemonic, char **args);
int			is_valid_args(char *mnemonic, char **args);

#endif
