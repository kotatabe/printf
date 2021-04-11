# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kotatabe <kotatabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/04 16:41:09 by ktabe             #+#    #+#              #
#    Updated: 2020/09/16 16:49:03 by kotatabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
INCS = -I ft_printf.h
SRCS = ft_printf.c utils_1.c utils_2.c formatter.c output_di.c output_cs.c\
 output_u.c output_x.c output_large_x.c output_p.c
OBJS = $(SRCS:.c=.o)

LIBSRCS = libft/*.c
LIBOBJS = $(LIBSRCS:.c=.o)

$(NAME): $(OBJS) $(LIBSRCS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re