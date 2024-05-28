# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 16:55:42 by nchebbi           #+#    #+#              #
#    Updated: 2024/05/24 16:09:24 by racinedelar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= printf.a

PNAME	= printf

SRCS	=	./printf/src/ft_printf.c\
			./printf/src/ft_printf_str.c\
			./printf/src/ft_printf_utils.c\
			./printf/src/ft_printf_hexa.c\
			./printf/src/ft_printf_unsignedint.c\
			./printf/src/ft_putchar_one.c\
			./printf/src/ft_printf_int_entier.c
			

OBJS	= ${SRCS:.c=.o}

CC	= 	cc

RM	= 	rm -f

CFLAGS = 	-Wall -Werror -Wextra

${NAME}:	${OBJS}
			$(MAKE) libft.a -C ../../libft
			cp ../libft.a ${NAME} 
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
			
all:		${NAME}

cmain:		${NAME}
			${CC} ${CFLAGS} main.c ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM}  ${NAME}
			${RM}  ${PNAME}
			$(MAKE) fclean -C ./libft
			
re: 		clean all

.PHONY:		all clean fclean re