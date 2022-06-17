




NAME = libpush_swap.a
SRC_DIR = ./srcs/
SRC_FILES = *.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

HEADER = ./includes/push_swap.h
O_FILES = $(SRC_FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@cd ./libft/ && $(MAKE) && cd ..;
	@cp ./libft/libft.a ./$(NAME);
	@gcc -c -Wall -Werror -Wextra -g -fsanitize=address $(HEADER) $(SRCS);
	@ar rc $(NAME) $(O_FILES);
	@mv $(O_FILES) $(SRC_DIR)
	@ranlib $(NAME);
	@gcc -Wall -Werror -Wextra -g -fsanitize=address -o push_swap push_swap.c -L. -lpush_swap
	@gcc -Wall -Werror -Wextra -g -fsanitize=address -o checker checker.c -L. -lpush_swap

clean:
	@cd ./libft/ && $(MAKE) clean && cd ..;
	@cd ./srcs/ && rm -f $(O_FILES) && cd ..;
	@rm -f ./srcs/$(O_FILES) ./includes/push_swap.h.gch;
	

fclean:
	@cd ./libft/ && $(MAKE) fclean && cd ..;
	@cd ./srcs/ && rm -f $(O_FILES) && cd ..;
	@rm -f $(NAME) ./includes/push_swap.h.gch;

re: fclean all