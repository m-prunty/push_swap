NAME = push_swap
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -g -I${INC} 
LIB = libft
INC = include
SRC_DIR	= src
OBJ_DIR	= obj

#SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_DIR)))
SRC_FILES = ${wildcard $(SRC_DIR)/*.c}
# $(addprefix $(SRC_DIR), ${wildcard *.c})

#OBJ	=  $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))


#(patsubst  *.c, *.o, $(PSRC))
#$(addprefix $(OBJ_DIR), $(SRC_FILES))

#OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all:	$(NAME)
	@echo ${SRC_FILES} ${OBJ}


$(NAME): ##$(OBJ)
		@cd $(LIB) && $(MAKE) #&& mv $(LIB).so ../
		$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME)  -L$(LIB) -Wl,-rpath=$(LIB) -lft

clean:
		@cd libft && $(MAKE) clean
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(LIB).so
		$(RM) $(NAME)

re: fclean all
