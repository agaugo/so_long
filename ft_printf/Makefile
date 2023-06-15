#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hflohil- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/05 14:00:44 by hflohil-      #+#    #+#                  #
#    Updated: 2022/10/07 13:07:39 by hflohil-      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

SRCS		=	utils/ft_extra.c utils/ft_hex.c utils/ft_ptr.c utils/ft_int.c utils/ft_strint.c ft_printf.c
OBJS		=	ft_extra.o ft_hex.o ft_ptr.o ft_int.o ft_strint.o ft_printf.o

NAME	= libftprintf.a
LIBFT	= libft/libft.a
GCC		= gcc
CFLAGS	= -Werror -Wextra -Wall

$(NAME):
	cd libft && make
	cp libft/libft.a $(NAME)
	$(GCC) $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) && cd libft && make clean

fclean:	clean
	rm -f $(NAME) && cd libft && make fclean

re:	clean fclean all

.PHONY: all clean fclean re