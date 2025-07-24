NAME =		push_swap

SRCS :=		$(wildcard *.c)
OBJS :=		$(SRCS:%.c=obj/%.o)
HDRS := 	$(wildcard include/*.h)

LIBFT_DIR =	libft
LIBFT =		$(LIBFT_DIR)/libft.a

CC =		cc
CFLAGS =	-Wall -Wextra -Werror -Iinclude -Ilibft
LIBS = 		-L$(LIBFT_DIR) -lft

TOTAL_SRCS := $(words $(SRCS))
SRC_NUM := 0

RESET = \033[0m
BOLD = \033[1m
RED = \033[31;2m
GREEN = \033[32m
YELLOW = \033[33m

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(BOLD)$(YELLOW)\n$(NAME) successfully compiled.$(RESET)"

obj/%.o: %.c $(HDRS)
	@mkdir -p $(@D)
	@$(eval SRC_NUM := $(shell expr $(SRC_NUM) + 1))
	@printf "$(BOLD)\rCompiling $(NAME): [$(SRC_NUM)/$(TOTAL_SRCS)] $< $(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $<


$(LIBFT): $(wildcard $(LIBFT_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.h)
	@echo ""
	@make -s -C $(LIBFT_DIR)

clean:
	@rm -rf obj
	@make clean -C $(LIBFT_DIR)
	@echo "$(BOLD)$(RED)Object files and libft.a removed.$(RESET)"

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(BOLD)$(RED)$(NAME) removed.$(RESET)"


re:	fclean all

.PHONY: all clean fclean re