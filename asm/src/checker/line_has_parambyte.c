/*
** line_has_parambyte.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr  5 14:11:00 2014 Laurent Fourrier
** Last update Sat Apr 12 10:35:37 2014 Laurent Fourrier
*/

char	g_no_parambyte[] = 
  {
    0x01, 0x09, 0x0C, 0x0F, 0x00
  };

char	line_has_parambyte(char opcode)
{
  int	it;

  it = 0;
  while (g_no_parambyte[it])
    {
      if (g_no_parambyte[it++] == opcode)
	return (0);
    }
  return (1);
}
