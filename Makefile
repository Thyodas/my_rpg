##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
	src/display/display_game.c \
	src/display/display_start_menu.c \
	src/display/display_start_menu_two.c \
	src/drawing/cursor.c \
	src/drawing/entity.c \
	src/init/init_player.c \
	src/init/cursor.c \
	src/init/window.c \
	src/init/entity.c \
	src/init/time.c \
	src/init/emitter.c \
	src/init/data.c \
	src/parser.c \
	src/interactions/is_hit.c \
	src/interactions/player_region_collision.c \
	src/utils/reader.c \
	src/utils/free.c \
	src/utils/help.c \
	src/utils/strings_tree.c \
	src/utils/strings_two.c \
	src/utils/strings.c \
	src/utils/coords.c \
	src/utils/lists/my_put_in_list.c \
	src/events/start_menu.c \
	src/events/mouse_events.c \
	src/events/animation.c \
	src/events/play_events.c \
	src/particles-engine/snow/gen_snow.c \
	src/particles-engine/snow/update_snow.c \
	src/particles-engine/utils_particles/utils_particles.c \
	src/particles-engine/draw_particles.c \
	src/particles-engine/particles_engine.c \
	src/particles-engine/blood/update_blood.c \
	src/particles-engine/blood/gen_blood.c \
	src/regions/create_region.c \
	src/regions/loop_region.c

OBJ    	=    	$(SRC:.c=.o)

INCDIR 	= 		include

CFLAGS 	= 		-I $(INCDIR) -g

NAME 	=     	my_rpg


all: $(NAME)

$(NAME):    $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L"lib/" -lmy -l csfml-graphics \
	-l csfml-window \
	-l csfml-system -l csfml-audio -Werror -Wextra -lm
	make clean

make_lib:
	make -C lib/my

clean:
	make clean -C lib/my
	rm -rf $(OBJ)

fclean:        clean
	make clean -C lib/my
	rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
