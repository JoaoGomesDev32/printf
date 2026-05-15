# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joagomes <joagomes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 16:16:14 by joagomes          #+#    #+#              #
#    Updated: 2026/05/15 13:31:14 by joagomes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprint.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_printf.c ft_format.c ft_put_utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re