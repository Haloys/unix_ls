##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME 	= my_ls

RM	= rm -f

MAKE 	= make

OBJ	= $(SRC:.c=.o)

INCLUDE = -I ./include/

LIB = -L ./lib/my/ -lmy

SRC =	src/main.c		\
	src/count.c		\
	src/count_a.c		\
	src/create_list.c	\
	src/create_list_a.c	\
	src/flag_d.c		\
	src/flag_l.c		\
	src/free.c		\
	src/order_flags.c	\
	src/parse_args.c	\
	src/popu_list.c		\
	src/popu_list_a.c	\
	src/sort.c		\
	src/sort_r.c		\
	src/sort_t.c		\
	src/calcul_total.c	\
	src/set_flag.c		\
	src/local_time.c

all: $(NAME)

$(NAME):
	cd lib/my/ && $(MAKE)
	gcc $(INCLUDE) -o $(NAME) $(SRC) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
