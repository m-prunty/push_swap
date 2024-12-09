NAME = push_swap
CC = cc 
RM = rm -f
INC = include/
CFLAGS = -Wall -Wextra -g -Werror 
LIB = libft
GNL = get_next_line
BON = bonus
SRC_DIR	= src
OBJ_DIR	= obj



SRC_FILES = ${wildcard $(SRC_DIR)/*.c}

all:	$(NAME)
	@echo ${SRC_FILES} ${OBJ}


$(NAME):
	cd $(LIB) && $(MAKE)  && cp ${LIB}.so ../${INC}/
	$(CC) $(CFLAGS) -I$(INC) $(SRC_FILES) -o $(NAME)  -L$(LIB) -Wl,-rpath=$(LIB) -lft

bonus: re 
	$(CC) $(CFLAGS) -I$(INC) $(BON)/checker.c -o chk -L$(LIB) -Wl,-rpath=$(LIB) -lft


clean:
	@cd libft && $(MAKE) clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB).so
	$(RM) $(NAME)

re: fclean all
