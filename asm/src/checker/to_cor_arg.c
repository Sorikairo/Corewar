/*
** to_cor_arg.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Apr  3 17:00:02 2014 Laurent Fourrier
** Last update Sat Apr  5 15:25:55 2014 Laurent Fourrier
*/

#include <tio.h>
#include <tutils.h>
#include "reader.h"
#include "checker.h"
#include "op.h"

t_cor_arg	to_cor_arg_register(char *arg)
{
  t_cor_arg	rtn;

  arg++;
  rtn.type = T_ERR;
  if (!utl_strisvalid(arg, "0123456789") || arg[0] == '\0')
    {
      rtn.val = ERR_REG_NAN;
      return (rtn);
    }
  rtn.val = utl_atoi(arg);
  if (rtn.val < 0 || rtn.val > 15)
    {
      rtn.val = ERR_REG_OUT;
      return (rtn);
    }
  rtn.type = T_REG;
  return (rtn);
}

int		get_label_diff(int mempos, char *label, t_label *list)
{
  while (list)
    {
      if (utl_strcmp(label, list->name) == 0)
	return (list->mem_pos - mempos);
      list = list->next;
    }
  return (mempos);
}

t_cor_arg	to_cor_arg_direct(char *arg, int mempos, t_label *label)
{
  t_cor_arg	rtn;

  arg++;
  rtn.type = T_ERR;
  if (arg[0] == LABEL_CHAR)
    {
      arg++;
      if (!label_exists(label, arg))
	{
	  rtn.val = ERR_LABEL;
	  return (rtn);
	}
      rtn.type = T_DIR;
      rtn.val = get_label_diff(mempos, arg, label);
    }
  if (!utl_strisvalid(arg, "0123456789") || arg[0] == '\0')
    {
      rtn.type = ERR_DIR_NAN;
      return (rtn);
    }
  rtn.val = utl_atoi(arg);
  rtn.type = T_DIR;
  return (rtn);
}

t_cor_arg	to_cor_arg_indirect(char *arg, int mempos, t_label *label)
{
  t_cor_arg	rtn;

  rtn.type = T_ERR;
  if (arg[0] == LABEL_CHAR)
    {
      arg++;
      if (!label_exists(label, arg))
	{
	  rtn.val = ERR_LABEL;
	  return (rtn);
	}
      rtn.type = T_IND;
      rtn.val = get_label_diff(mempos, arg, label);
    }
  if (!utl_strisvalid(arg, "0123456789") || arg[0] == '\0')
    {
      rtn.type = ERR_IND_NAN;
      return (rtn);
    }
  rtn.val = utl_atoi(arg);
  rtn.type = T_IND;
  return (rtn);
}

t_cor_arg	to_cor_arg(char *arg, int mempos, t_label *label)
{
  if (arg[0] == 'r')
    return (to_cor_arg_register(arg));
  else if (arg[0] == '%')
    return (to_cor_arg_direct(arg, mempos, label));
  return (to_cor_arg_indirect(arg, mempos, label));
}
