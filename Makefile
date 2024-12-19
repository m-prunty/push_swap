################################################################################
#                                     CONFIG                                   #
################################################################################
NAME	:= push_swap
FLAGS	:= -Wall -Wextra -g -Werror 
LDFLAGS	:= -L./libft -lft
INCLUDE	:= -I./libft/include/ -I./include/
SRCDIR	:= src
OBJDIR	:= obj


CC := gcc ${FLAGS} ${INCLUDE} 
################################################################################
#                                     COLOURS                                  #
################################################################################
CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m
PURPLE      := \033[1;35m
BOLD        := \033[1m
################################################################################
#                                  ALL SRCS                                    #
################################################################################

SRC = ${wildcard $(SRCDIR)/*.c}

################################################################################
#                                 CREATE OBJS                                  #
################################################################################
OBJECTS  := $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))
ALL_OBJS := $(OBJECTS) 
################################################################################
#                                 PROGRESS BAR                                 #
################################################################################
TOTAL_FILES = $(shell echo $(ALL_OBJS) | wc -w)
CURR_FILE   = 0

define progress_bar
$(eval CURR_FILE = $(shell expr $(CURR_FILE) + 1))
@printf "\r$(CYAN)⌛ [%-50s] %d/%d files\n" "$$(printf '#%.0s' $$(seq 1 $$(expr $(CURR_FILE) \* 50 / $(TOTAL_FILES))))" $(CURR_FILE) $(TOTAL_FILES)
endef
################################################################################
#                                COMPILATION                                   #
################################################################################
all: banner $(NAME) 
	@printf "\n$(GREEN)✨ Project compiled successfully!$(CLR_RMV)\n"

banner:
	@printf "%b" "$(PURPLE)"
	@echo "╔═══════════════════════════════════════════════════════════════╗"
	@echo "║                         Building push_swap                    ║"
	@echo "╚═══════════════════════════════════════════════════════════════╝"
	@printf "%b" "$(CLR_RMV)"

$(NAME):  $(ALL_OBJS) libft
	@$(CC) -o $(NAME) $(ALL_OBJS) $(LDFLAGS)
	@echo "\n$(GREEN)✅ All files compiled successfully!$(CLR_RMV)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR) 
	@$(CC) $(FLAGS) -c $< -o $@
	$(call progress_bar)

libft:
	@printf "$(BLUE)📚 Building libft...$(CLR_RMV)\n"
	@make -C $(LFT)
	@printf "$(GREEN)✓ Libft ready!$(CLR_RMV)\n"


clean:
	@printf "$(RED)🧹 Cleaning object files...$(CLR_RMV)\n"
	@rm -f $(OBJECTS)
	@printf "$(GREEN)✓ Clean complete!$(CLR_RMV)\n"

fclean: clean
	@make -C $(LFT) fclean
	@printf "$(RED)🗑️  Removing executables...$(CLR_RMV)\n"
	@rm -f $(NAME)
	@printf "$(GREEN)✓ Full clean complete!$(CLR_RMV)\n"

re: fclean all


.PHONY: all clean fclean re bonus banner

################################################################################
#                                 END                                          #
################################################################################
