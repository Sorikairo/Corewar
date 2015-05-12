##
## Makefile for corewar in /home/fourri_l/Projects/CPE_2014_corewar
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Sun Apr 13 17:38:06 2014 Laurent Fourrier
## Last update Sun Apr 13 17:42:28 2014 Laurent Fourrier
##

DIR_ASM		=	asm

DIR_VM		=	corewar

NAME_ASM	=	$(DIR_ASM)/asm

NAME_VM		=	$(DIR_VM)/corewar

all: $(NAME_ASM) $(NAME_VM)

$(NAME_ASM):
	cd $(DIR_ASM) && make

$(NAME_VM):
	cd $(DIR_VM) && make

clean:
	cd $(DIR_ASM) && make clean
	cd $(DIR_VM) && make clean

fclean: clean
	cd $(DIR_ASM) && make fclean
	cd $(DIR_VM) && make fclean

re: fclean all

.PHONY: all clean fclean re
