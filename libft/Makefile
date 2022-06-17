# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjokela <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 14:50:10 by mjokela           #+#    #+#              #
#    Updated: 2021/11/03 14:50:14 by mjokela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBFT_FILES = ft_atoi.c ft_bzero.c ft_count_delimited_words.c ft_dstrlen.c \
ft_intlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_fill_array.c ft_free_array.c

PRINTF_FILES = checking_and_dispatching.c ft_printf.c \
little_helpers.c print_char.c print_float.c print_hex.c print_int.c \
print_modulo.c print_octal.c print_pointer.c print_string.c \
print_uint.c reading.c float_helpers.c print_bits.c

HEADER = libft.h
SRCS = $(addprefix libft_functions/, $(LIBFT_FILES)) \
get_next_line/get_next_line.c  $(addprefix ft_printf/srcs/, $(PRINTF_FILES))
O_FILES = $(LIBFT_FILES:.c=.o) get_next_line.o  $(PRINTF_FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(HEADER) $(SRCS);
	@ar rc $(NAME) $(O_FILES);
	@ranlib $(NAME);

clean:
	@rm -f $(O_FILES)  libft.h.gch;

fclean:	
	@rm -f $(O_FILES) $(NAME) libft.h.gch;

re: fclean all
