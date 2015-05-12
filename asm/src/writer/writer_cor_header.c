/*
** writer_cor_header.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Mar 30 18:00:27 2014 Laurent Fourrier
** Last update Sun Apr 13 15:35:58 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "reader.h"
#include "utils.h"
#include "op.h"

header_t	new_header()
{
  int		it;
  header_t	rtn;

  rtn.magic = COREWAR_EXEC_MAGIC;
  it = 0;
  while (it < PROG_NAME_LENGTH + 1)
    rtn.prog_name[it++] = 0;
  it = 0;
  while (it < COMMENT_LENGTH + 1)
    rtn.comment[it++] = 0;
  rtn.prog_size = 0;
  return (rtn);
}

void		writer_cor_header(t_file *file, t_cor_file *cor)
{
  header_t	header;

  header = new_header();
  utl_strcat(header.prog_name, cor->name);
  utl_strcat(header.comment, cor->comment);
  header.prog_size = cor->file_size;
  write_data_be(file, &header.magic, 4);
  write_data(file, header.prog_name, PROG_NAME_LENGTH);
  write_data_be(file, &header.prog_size, 4);
  write_data(file, header.comment, COMMENT_LENGTH);
}
