##
## EPITECH PROJECT, 2024
## make
## File description:
## make
##

NAME	=	my_rpg

SRC		=	src/main.c	 				\
			src/anim.c					\
			src/what_disp.c				\
			src/event_gestion.c			\
			src/inventory.c				\
			src/player.c				\
			src/player_move.c			\
			src/my_str_to_word_array.c	\
			src/load_map.c				\
			src/what_disp2.c			\
			src/pausemenu.c				\
			src/handle_png.c			\
			src/handle_dialog.c			\
			src/where_tp.c				\
			src/player_inventory.c 		\
			src/event_gestion2.c		\
			src/player_inventory2.c		\
			src/end_game.c				\
			src/transition.c			\
			src/init_ennemy.c			\
			src/dead.c					\
			src/next_init_ennemy.c

OBJ		=	$(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

DEBUGFLAGS	=	--leak-check=full --show-leak-kinds=all -s

OTHERDEBUGFLAGS	=	--track-origins=yes --log-file="data"

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFML) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

run:	re
	./$(NAME)
	make fclean
	clear

debug: fclean
	gcc -g3 -o $(NAME) $(SRC) $(CSFML)
	valgrind $(DEBUGFLAGS) $(OTHERDEBUGFLAGS) ./$(NAME)
	make fclean
