/*
** utils.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Apr  7 13:41:46 2014 Laurent Fourrier
** Last update Sun Apr 13 06:07:59 2014 Laurent Fourrier
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <tio.h>
# include "op.h"

/*
** God praise this function
*/
void	*xmalloc(int size);

/*
** Endian related functions
*/
char	is_big_endian();
void	invert_endianness(void *data, int size);
void	*read_data_be(t_file *file, void *data, int size);
short	byte_toshort_be(char *byte);
int	byte_toint_be(char *byte);

/*
** Corewar related functions
*/
char	get_arg_type(char parambyte, char arg_nbr);
op_t	get_op_info(char opcode);

#endif
