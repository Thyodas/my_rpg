##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

FILE_NAME	:=	main 													\
			drawing/cursor 												\
			drawing/entity 												\
			init/cursor 												\
			init/window 												\
			init/entity 												\
			init/time 													\
			init/emitter 												\
			init/data 													\
			interactions/entity_region_collision 						\
			utils/free 													\
			utils/help 													\
			utils/arr_copy 												\
			utils/cut_str 												\
			utils/coords 												\
			utils/extend_str 											\
			utils/random 												\
			utils/lists/my_put_in_list 									\
			utils/lists/my_list_size 									\
			utils/atof													\
			utils/normalize												\
			events/mouse_events 										\
			events/exit 												\
			events/play_events 											\
			particles-engine/snow/gen_snow 								\
			particles-engine/snow/update_snow 							\
			particles-engine/utils_particles/utils_particles 			\
			particles-engine/draw_particles 							\
			particles-engine/particles_engine 							\
			particles-engine/blood/update_blood 						\
			particles-engine/blood/gen_blood 							\
			regions/create_region 										\
			regions/loop_region 										\
			regions/change_region 										\
			regions/parser 												\
			scene/set_scene 											\
			scene/game/display 											\
			scene/game/events_handler 									\
			scene/game/init 											\
			scene/settings/display 										\
			scene/settings/events_handler 								\
			scene/settings/init 										\
			scene/start_menu/display 									\
			scene/start_menu/event_handler 								\
			scene/start_menu/init 										\
			scene/pause/display 										\
			scene/pause/events_handler 									\
			scene/pause/init 											\
			scene/help/display 											\
			scene/help/events_handler 									\
			scene/help/init 											\
			scene/draw_object 											\
			scene/handle_object 										\
			scene/parse_object											\
			scene/return_to_previous_scene 								\
			maps/create_map 											\
			objects/player/create 										\
			objects/player/handler 										\
			objects/player/draw 										\
			objects/create_object 										\
			objects/teleporter/draw 									\
			objects/teleporter/create 									\
			objects/teleporter/parser 									\
			objects/teleporter/handler 									\
			objects/buttons/create 										\
			objects/buttons/draw_start 									\
			objects/buttons/handler_start 								\
			objects/buttons/parser										\
			clock/handle_clock											\
			objects/smoke/create 										\
			objects/smoke/draw 											\
			objects/smoke/handler 										\
			objects/smoke/parser 										\
			objects/waves/create 										\
			objects/waves/draw 											\
			objects/waves/handler 										\
			objects/waves/parser 										\
			settings/reset_settings 									\
			settings/set_general_volume 								\
			settings/set_music_volume									\
			objects/dialogue/create 									\
			objects/dialogue/draw 										\
			objects/dialogue/handler	 								\
			objects/dialogue/parser										\
			objects/enemy/props_enemy/option_enemy  					\
			objects/enemy/props_enemy/stats_enemy  						\
			objects/enemy/handler    									\
			objects/enemy/create   										\
			objects/enemy/parser 										\
			objects/enemy/draw											\


BUILD_DIR 	:=		build/

SRC_DIR		:=		src/

EXT			:=		.c

FILE		:= 		$(addsuffix $(EXT), $(FILE_NAME))

SRC         :=      $(addprefix $(SRC_DIR), $(FILE))

INC_DIR 	:= 		include/

LIB			:=		-l csfml-graphics -l csfml-window
LIB			+=		-l csfml-system -l csfml-audio -lm

OBJECTS    	:=    	$(addprefix $(BUILD_DIR), $(SRC:$(SRC_DIR)%.c=%.o))

NAME 		:=     	my_rpg

CFLAGS 		:= 		$(LIB) -ggdb3 -O1 -g


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
