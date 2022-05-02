##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
	src/display/display_game.c \
	src/display/display_start_menu.c \
	src/drawing/cursor.c \
	src/drawing/entity.c \
	src/init/cursor.c \
	src/init/window.c \
	src/init/entity.c \
	src/init/time.c \
	src/init/emitter.c \
	src/init/data.c \
	src/init/start_menu.c \
	src/interactions/is_hit.c \
	src/interactions/player_region_collision.c \
	src/utils/free.c \
	src/utils/help.c \
	src/utils/arr_copy.c \
	src/utils/cut_str.c \
	src/utils/coords.c \
	src/utils/extend_str.c \
	src/utils/random.c \
	src/utils/lists/my_put_in_list.c \
	src/events/mouse_events.c \
	src/events/exit.c \
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
	src/regions/loop_region.c \
	src/regions/change_region.c \
	src/regions/parser.c \
	src/scene/set_scene.c \
	src/maps/create_map.c \
	src/objects/player/create.c \
	src/objects/player/handler.c \
	src/objects/inventory/create.c \
	src/objects/inventory/handler.c \
	src/objects/create_object.c \
	src/objects/teleporter/draw.c \
	src/objects/teleporter/create.c \
	src/objects/teleporter/parser.c \
	src/objects/teleporter/handler.c \
	src/objects/buttons/create.c \
	src/objects/buttons/draw_start.c \
	src/objects/buttons/handler_start.c \
	src/objects/buttons/parser.c

OBJ    	:=    	$(SRC:.c=.o)

INCDIR 	:= 		./include

CFLAGS 	:= 		-I$(INCDIR) -ggdb3 -O1

NAME 	:=     	my_rpg


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
