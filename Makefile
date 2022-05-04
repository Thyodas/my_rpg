##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

FILE	:=	main.c 														\
			display/display_game.c 										\
			display/display_start_menu.c 								\
			drawing/cursor.c 											\
			drawing/entity.c 											\
			init/cursor.c 												\
			init/window.c 												\
			init/entity.c 												\
			init/time.c 												\
			init/emitter.c 												\
			init/data.c 												\
			init/start_menu.c 												\
			interactions/is_hit.c 										\
			interactions/player_region_collision.c 						\
			utils/free.c 												\
			utils/help.c 												\
			utils/arr_copy.c 											\
			utils/cut_str.c 											\
			utils/coords.c 												\
			utils/extend_str.c 											\
			utils/random.c 												\
			utils/lists/my_put_in_list.c 								\
			events/start_menu.c 										\
			events/mouse_events.c 										\
			events/animation.c 											\
			events/play_events.c 										\
			particles-engine/snow/gen_snow.c 							\
			particles-engine/snow/update_snow.c 						\
			particles-engine/utils_particles/utils_particles.c 			\
			particles-engine/draw_particles.c 							\
			particles-engine/particles_engine.c 						\
			particles-engine/blood/update_blood.c 						\
			particles-engine/blood/gen_blood.c 							\
			regions/create_region.c 									\
			regions/loop_region.c 										\
			regions/change_region.c 									\
			regions/parser.c 											\
			scene/set_scene.c 											\
			maps/create_map.c 											\
			objects/player/create.c 									\
			objects/player/handler.c 									\
			objects/create_object.c 									\
			objects/teleporter/draw.c 									\
			objects/teleporter/create.c 								\
			objects/teleporter/parser.c 								\
			objects/teleporter/handler.c 								\
			objects/enemy/draw.c 										\
			objects/enemy/create.c 										\
			objects/enemy/parser.c 										\
			objects/enemy/handler.c 									\
			objects/enemy/props_enemy/stats_enemy.c						\
			objects/enemy/props_enemy/option_enemy.c					\

BUILD_DIR 	:=		build/

SRC_DIR		:=		src/

SRC         :=      $(addprefix $(SRC_DIR), $(FILE))

INC_DIR 	:= 		include/

LIB			:=		-l csfml-graphics -l csfml-window
LIB			+=		-l csfml-system -l csfml-audio -lm

OBJECTS    	:=    	$(addprefix $(BUILD_DIR), $(SRC:$(SRC_DIR)%.c=%.o))

NAME 		:=     	my_rpg

CFLAGS 		:= 		$(LIB) -ggdb3 -O1


all: $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C lib/my/
	@gcc $(OBJECTS)  -L ./lib/my -lmy $(CFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BUILD_DIR)

re: fclean all
