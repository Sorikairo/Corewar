##
## Makefile for tlist in /home/fourri_l/Projects/lib/tlist
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Thu Jan 23 10:14:22 2014 Laurent Fourrier
## Last update Mon Feb  3 11:24:34 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

LIBDIR	=	lib

SRCDIR	=	src

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-iquote$(INCDIR) \
		-I$(LIBDIR)/include

SRC	=	$(SRCDIR)/add_elem.c \
		$(SRCDIR)/iterate.c \
		$(SRCDIR)/rm_elem.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtlist.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
