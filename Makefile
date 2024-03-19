# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:51:42 by mamichal          #+#    #+#              #
#    Updated: 2024/03/19 13:00:38 by mamichal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

# Variables
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ./includes/ft_printf.h
RM = rm -fr
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Paths and Files
VPATH = src:src/utils
SRC = ft_printf.c \
		buffer.c \
		ft_ltoa_base.c \
		number_utils.c \
		parser.c \
		render.c \
		render_char.c \
		render_number.c \
		render_string.c \
		utils.c

OBJ = $(addprefix obj/,$(SRC:.c=.o))


# Rules
all: $(NAME)

bonus: all

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_PATH) all

obj:
	mkdir -p obj

obj/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@ -include $(INCLUDES) 

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) obj 

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re:	fclean all

.SILENT:

.PHONY: all bonus libft clean fclean re
