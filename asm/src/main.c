/*
** main.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 15:47:57 2014 Laurent Fourrier
** Last update Sat Apr  5 15:23:47 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include "asm.h"
#include "utils.h"

/*
** TODO : remove the ability to put output file
*/

void		print_usage(char *exc)
{
  write_str(g_fstdout, "Usage: ");
  write_str(g_fstdout, exc);
  write_str(g_fstdout, " ASM_FILE\n");
  flush_file(g_fstdout);
}

int		main(int argc, char **argv)
{
  char		*output;

  open_fstd();
  if (argc < 2)
    print_usage(argv[0]);
  else if (argc < 3)
    {
      output = change_filext(argv[1], ".cor");
      assemble_cor(argv[1], output);
      free(output);
    }
  else
    assemble_cor(argv[1], argv[2]);
  close_fstd();
  return (0);
}
