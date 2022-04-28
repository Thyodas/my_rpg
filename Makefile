##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=		$(shell find src/ -name "*.c")

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
