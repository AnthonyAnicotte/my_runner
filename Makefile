##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib
##

SRC	=	src/main.c  \
	    src/event.c \
	    src/game_and_menus.c    \
		 src/creation.c	 \
	    src/draw_set_display.c  \
	    src/my_revstr_no_display.c	\
	    src/check_function.c    \
	    src/destroy_function.c  \
	    src/int_to_char.c	\
	    src/move_rect.c	\
	    src/create_game.c	\
		src/multiple_ennemies.c
NAME	=	my_runner

OBJ	=	$(SRC:.c=.o)
CFLAGS	=	-W -Wall -Wextra -lcsfml-window -lcsfml-audio -lcsfml-graphics -lcsfml-system -I include/

all:		$(NAME)

$(NAME):	$(OBJ)

		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:	
		rm -f $(OBJ)
		rm -rf *~
		rm -rf src/*~

fclean:		clean
		rm -f $(NAME)

re:		fclean all
