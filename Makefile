# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/03 13:39:07 by rtarasen          #+#    #+#              #
#    Updated: 2018/02/09 17:14:24 by rtarasen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes/

#libft
LFT_SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strarr_new.c ft_strarr_del.c ft_lstlen.c \
ft_lstfind.c ft_arrtolst.c ft_lstdelcontent.c ft_itoa_base.c get_next_line.c \
ft_uchar.c ft_count_active_bytes.c ft_power.c ft_ftoa.c
LFT_OBJ = $(LFT_SRCS:.c=.o)

#ft_printf
FT_PRINTF_SRCS = ./ft_printf/ft_printf.c ./ft_printf/handle_conversion_specs.c \
./ft_printf/handle_chars.c ./ft_printf/handle_integers.c ./ft_printf/t_specs.c \
./ft_printf/utils.c ./ft_printf/utils_int.c ./ft_printf/handle_other.c \
./ft_printf/handle_floating_point.c
FT_PRINTF_OBJ = $(FT_PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FT_PRINTF_OBJ) $(LFT_OBJ)
	ar rc $(NAME) $(FT_PRINTF_OBJ) $(LFT_OBJ)
	ranlib $(NAME)

clean:
	rm -f ./*.o
	rm -f ./ft_printf/*.o

fclean: clean
	rm -f ./$(NAME)

re: fclean all