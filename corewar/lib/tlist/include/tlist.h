/*
** tlist.h for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jan 22 09:26:59 2014 Laurent Fourrier
** Last update Thu Jan 23 10:22:35 2014 Laurent Fourrier
*/

#ifndef TLIST_H_
# define TLIST_H_

typedef struct	s_list
{
  struct s_list	*prev;
  void		*data;
  struct s_list	*next;
}		t_list;

typedef t_list	*(*it_func)(t_list*, t_list*, void*);

t_list	*tl_add_elem(t_list *list, void *data);
t_list	*tl_rm_elem(t_list *list, t_list *elem);

t_list	*tl_iterate(t_list *list, void *param, it_func func);

#endif
