################################################################################
#                                     CONFIG                                   #
################################################################################
NAME        := push_swap
FLAGS       := -Wall -Wextra -Werror -g
LIBFT       := ./libft
LIBFT_LIB   := $(LIBFT)/libft.a
LDFLAGS     := -L$(LIBFT) -lft
INCLUDE     := -I$(LIBFT)/include -Iinclude
SRCDIR      := src
OBJDIR      := obj

CC          := gcc $(FLAGS) $(INCLUDE)
################################################################################
#                                    COLOURS                                   #
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
#                                 SOURCE FILES                                 #
################################################################################
SRCS         := $(wildcard $(SRCDIR)/*.c)
OBJS        := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

################################################################################
#                                 PROGRESS BAR                                 #
################################################################################
TOTAL_FILES := $(words $(OBJS))
CURR_FILE   := 0

define progress_bar
    $(eval CURR_FILE = $(shell expr $(CURR_FILE) + 1))
    @printf "\r$(CYAN)⌛ [%-50s] %d/%d files$(CLR_RMV)" \
            "$$(printf '#%.0s' $$(seq 1 $$(expr $(CURR_FILE) \* 50 / $(TOTAL_FILES))))" \
            $(CURR_FILE) $(TOTAL_FILES)
endef

################################################################################
#                                    RULES                                     #
################################################################################
all: $(LIBFT_LIB) banner $(NAME)

$(NAME):  $(OBJS)
	@$(CC) $^ $(LDFLAGS) -o $@
	@printf "\n$(GREEN)✨ $(NAME) compiled successfully!$(CLR_RMV)\n"

bonus: $(NAME) $(BONUS_OBJS)
	@$(CC) -o checker) $(BONUS_OBJS) $(LDFLAGS)
	@printf "$(GREEN)✨ $(NAME) compiled successfully!$(CLR_RMV)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	$(call progress_bar)

$(LIBFT_LIB):
	@printf "$(BLUE)📚 Building libft...$(CLR_RMV)\n"
	@make -C $(LIBFT)
	@printf "$(GREEN)✓ Libft ready!$(CLR_RMV)\n"

banner:
	@printf "%b" "$(PURPLE)"
	@echo "╔═══════════════════════════════════════════════════════════════╗"
	@echo "║                      Building push_swap                       ║"
	@echo "╚═══════════════════════════════════════════════════════════════╝"
	@printf "%b" "$(CLR_RMV)"

clean:
	@printf "$(RED)🧹 Cleaning object files...$(CLR_RMV)\n"
	@rm -rf $(OBJDIR)
	@printf "$(GREEN)✓ Clean complete!$(CLR_RMV)\n"

fclean: clean
	@printf "$(RED)🗑️  Removing executables...$(CLR_RMV)\n"
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@printf "$(GREEN)✓ Full clean complete!$(CLR_RMV)\n"

re: fclean all

.PHONY: all clean fclean re banner progress_bar 

################################################################################
#                                     END                                      #
################################################################################
