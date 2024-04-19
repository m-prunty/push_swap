NAME = push_swap
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iinclude 
LIB = libft.a

SRC_DIR	= src/
OBJ_DIR	= obj/

SRC_FILES = push_swap
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		@cd libft && $(MAKE) && mv $(LIB) ../
		$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
		@cd libft && $(MAKE) clean
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(LIB)
		$(RM) $(NAME)

re: fclean all
