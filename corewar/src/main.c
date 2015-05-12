/*
** main.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr  5 15:31:42 2014 Laurent Fourrier
** Last update Sun Apr 13 14:57:41 2014 Laurent Fourrier
*/

#include <tio.h>
#include "arena.h"

int		main(int argc, char **argv)
{
  t_arena	arena;

  open_fstd();
  if (argc > 2 && argc < 7)
    {
      arena = new_arena();
      load_all_champions(&arena, argc - 1, argv + 1);
      arena_loop(&arena);
      print_winner(&arena);
      destroy_arena(&arena);
    }
  else
    {
      write_str(g_fstdout, "Invalid number of champions\n");
      flush_file(g_fstdout);
    }
  close_fstd();
  return (0);
}
