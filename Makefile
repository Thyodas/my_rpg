##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
	src/display/start_menu.c \
	src/drawing/cursor.c \
	src/drawing/button.c \
	src/init/cursor.c \
	src/init/window.c \
	src/init/button.c \
	src/init/data.c \
	src/parser.c \
	src/utils/reader.c \
	src/utils/free.c \
	src/utils/help.c \
	src/utils/strings_tree.c \
	src/utils/strings_two.c \
	src/utils/strings.c \
	src/events/start_menu.c \
	src/events/mouse_events.c \

OBJ    =    $(SRC:.c=.o)

NAME =     my_rpg

INCDIR = include

CFLAGS = -I $(INCDIR) -g

all: $(NAME)

$(NAME):    $(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -L"lib/" -lmy -l csfml-graphics -l csfml-window \
	-l csfml-system -l csfml-audio -Werror -Wextra -lm

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
