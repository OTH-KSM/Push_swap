CFLAGS = -Wall -Wextra -Werror
SRC = TheMandatory/push_swap.c TheMandatory/check_args.c TheMandatory/check_what.c TheMandatory/instruction.c TheMandatory/small_sort.c TheMandatory/big_sort.c TheMandatory/big_sort_utils.c TheMandatory/big_sort_parts.c TheMandatory/double_instruction.c
BONUS_SRC = TheChecker/checker.c TheChecker/checker_instruction.c TheChecker/checker_double_instruction.c TheMandatory/check_args.c TheMandatory/check_what.c
SRCGNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = $(SRC:%c=%o) $(SRCGNL:%c=%o)
BONUS_OBJ = $(BONUS_SRC:%c=%o) $(SRCGNL:%c=%o)
LIBFT = libft/libft.a
PRINTF =  ft_printf/libftprintf.a
NAME = push_swap
BONUS_NAME = checker

all : $(NAME) $(LIBFT) $(PRINTF)

bonus : $(BONUS_NAME) $(LIBFT) $(PRINTF) $(SRCGNL)

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJ) $(LIBFT) $(PRINTF) $(SRCGNL)
	@$(CC) $(CFLAGS) $(BONUS_SRC) $(LIBFT) $(PRINTF) $(SRCGNL) -o $(BONUS_NAME)

$(LIBFT) :
	@$(MAKE) -C libft -s >/dev/null

$(PRINTF) : 
	@$(MAKE) -C ft_printf -s >/dev/null

bonus : $(BONUS_OBJ) $(LIBFT) $(PRINTF) $(SRCGNL)
	

clean :
	@rm -rf $(OBJ)
	@rm -rf $(BONUS_OBJ)
	@$(MAKE) -C libft clean -s >/dev/null
	@$(MAKE) -C ft_printf clean -s >/dev/null
	@echo "Cleanig done ✅"

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)
	@rm -rf $(LIBFT)
	@rm -rf $(PRINTF)
	@echo "Fcleanig done ✅"

re : fclean all