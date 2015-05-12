/*
** arena.h for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr  5 16:00:40 2014 Laurent Fourrier
** Last update Sun Apr 13 14:51:20 2014 Laurent Fourrier
*/

#ifndef ARENA_H_
# define ARENA_H_

# include <tlist.h>
# include "champion.h"
# include "op.h"

typedef struct	s_arena
{
  char		memory[MEM_SIZE];
  int		last_id;
  int		playing;
  int		live_count;
  int		cycle_to_die;
  t_list	*processes;
  t_list	*champions;
}		t_arena;

/*
** Let's get classy (:D)
*/
t_arena		new_arena();
void		destroy_arena(t_arena *arena);

/*
** Loading functions
*/
int		load_champion(t_arena *arena, t_file *file,
			      char *param, int offset);
int		load_all_champions(t_arena *arena, int chmp_nbr, char **chmp);

/*
** Running functions
*/
void		arena_loop(t_arena *arena);
void		kill_champion(t_arena *arena, t_champion *champion);
void		update_game_state(t_arena *arena);
void		print_winner(t_arena *arena);

/*
** Getters / Writers
*/
void		*get_memory_data(t_arena *arena, int address, int size);
void		*get_memory_data_be(t_arena *arena, int address, int size);
void		write_memory_data(t_arena *arena, void *data,
				  int address, int size);
void		write_memory_data_be(t_arena *arena, void *data,
				     int address, int size);

/*
** Advanced getters / writers
*/
char		get_register_index(t_arena *arena, int address);
int		get_indirect_value(t_arena *arena, int address);
t_champion	*get_champion_by_id(t_arena *arena, int id);
void		write_to_indirect(t_arena *arena, int pc,
				  int address, int value);

#endif
