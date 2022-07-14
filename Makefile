# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjokela <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 15:09:43 by mjokela           #+#    #+#              #
#    Updated: 2022/06/21 15:09:51 by mjokela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpush_swap.a
SRC_DIR = ./srcs/
SRC_FILES = checking.c commands.c data_manipulation.c minimax.c output.c \
pushing_and_swapping.c read_input.c rev_rotating.c rotating.c segments.c \
solver.c sort_small.c
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
	@gcc -Wall -Werror -Wextra -o push_swap push_swap.c -g -fsanitize=address -L. -lpush_swap
	@gcc -Wall -Werror -Wextra -o checker checker.c -g -fsanitize=address -L. -lpush_swap

clean:
	@cd ./libft/ && $(MAKE) clean && cd ..;
	@cd ./srcs/ && rm -f $(O_FILES) && cd ..;
	@rm -f ./srcs/$(O_FILES) ./includes/push_swap.h.gch;
	

fclean:
	@cd ./libft/ && $(MAKE) fclean && cd ..;
	@cd ./srcs/ && rm -f $(O_FILES) && cd ..;
	@rm -f $(NAME) ./includes/push_swap.h.gch checker push_swap;

re: fclean all
