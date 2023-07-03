# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 10:42:56 by wel-safa          #+#    #+#              #
#    Updated: 2023/07/03 17:08:37 by wel-safa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
SRC	:= ft_printf.c ft_printf_base.c ft_printf_putnbr.c
OBJS := ${SRC:.c=.o}

CFLAGS := -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
