NAME = teste
LIBFT = libs/libft/libft.a
CFLAGS = -Wall -Werror -Wextra -O3 -g3 -I/usr/include/readline
LDFLAGS = -lreadline -lhistory
LIBFT_PATH = libs/libft
OBJ_PATH = bin/
SRC_PATH = src/
TEMP_PATH = temp/

GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;35m
RESET = \033[0m

CFILES = main.c \
		readlines.c \
		start.c \
		input.c \
		garbage.c \
		prompt_check.c \
		prompt_handling.c \
		error.c \
		split_prompt.c \




OBJECTS = $(addprefix $(OBJ_PATH), $(CFILES:.c=.o))

INCLUDES = -I ./includes

all: libft $(OBJ_PATH) $(NAME)

libft:
	@make -C $(LIBFT_PATH) --no-print-directory


$(NAME): $(OBJECTS)
	@printf "\n$(CYAN)Creating $(NAME)$(RESET)\n\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME) $(INCLUDES) $(LDFLAGS)

$(OBJECTS): $(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(GREEN)Compiling $(notdir $(<))$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@if [ -d $(OBJ_PATH) ]; then \
		printf "$(RED)Cleaning $(OBJ_PATH)$(RESET)\n"; \
		rm -f $(OBJECTS) -r $(OBJ_PATH); \
	fi
	@make -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	@printf "$(RED)Cleaning $(NAME)$(RESET)\n"
	@rm -rf $(NAME)
	@if [ -d $(TEMP_PATH) ]; then \
		printf "$(RED)Cleaning $(TEMP_PATH)$(RESET)\n"; \
		rm -fr $(TEMP_PATH); \
	fi
	@make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all

make_temp:
	@mkdir -p $(TEMP_PATH)

n: all
	./$(NAME)

valgrind: make_temp all
	@valgrind -s -q --leak-check=full \
	--show-reachable=yes \
	--show-leak-kinds=all \
	--track-origins=yes \
	--track-fds=yes \
	--suppressions=./sup/suppresion.supp \
	--log-file=$(TEMP_PATH)valgrind.log ./$(NAME)

.PHONY: all clean fclean re libft make_temp tests n