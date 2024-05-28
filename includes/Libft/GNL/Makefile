# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:10:17 by nchebbi           #+#    #+#              #
#    Updated: 2024/05/28 02:57:05 by racinedelar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

PNAME =		a.out

SRCS = 		./src/get_next_line.c\
			./src/get_next_line_utils.c

OBJS = 		${SRCS:.c=.o}

CC = 		cc

RM = 		rm -f

CFLAGS = 	-Wall -Werror -Wextra -Ilibft

${NAME}:	${OBJS}
				$(MAKE) libft.a -C ./libft
				cp libft/libft.a ${NAME}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}
all :		${NAME}

cmain:		${NAME}
					${CC} ${CFLAGS} maingnl.c ${NAME}
				
clean:			
			${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}
					${RM} ${PNAME}
					${MAKE} fclean -C ./GNL
				
re:			clean all

.PHONY:		all clean fclean re
