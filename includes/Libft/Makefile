# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 13:36:27 by nchebbi           #+#    #+#              #
#    Updated: 2024/06/04 21:33:08 by racinedelar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

PNAME	= a.out

# List your libft source files here
SRCS	=	./src/ft_atoi.c ./src/ft_bzero.c ./src/ft_calloc.c ./src/ft_isalnum.c ./src/ft_isalpha.c ./src/ft_isascii.c ./src/ft_isdigit.c ./src/ft_isprint.c ./src/ft_itoa.c ./src/ft_memchr.c ./src/ft_memcmp.c ./src/ft_memcpy.c ./src/ft_memmove.c\
			./src/ft_memset.c ./src/ft_putchar_fd.c ./src/ft_putendl_fd.c ./src/ft_putnbr_fd.c ./src/ft_putstr_fd.c ./src/ft_split.c ./src/ft_strchr.c ./src/ft_strdup.c ./src/ft_striteri.c ./src/ft_strjoin.c ./src/ft_strlcat.c ./src/ft_strlcpy.c\
			./src/ft_strlen.c ./src/ft_strmapi.c ./src/ft_strncmp.c ./src/ft_strnstr.c ./src/ft_strrchr.c ./src/ft_strtrim.c ./src/ft_substr.c ./src/ft_tolower.c ./src/ft_toupper.c ./src/ft_addstr.c\
			./src/bonus/ft_lstadd_back.c ./src/bonus/ft_lstadd_front.c ./src/bonus/ft_lstclear.c ./src/bonus/ft_lstdelone.c ./src/bonus/ft_lstiter.c ./src/bonus/ft_lstlast.c ./src/bonus/ft_lstmap.c ./src/bonus/ft_lstnew.c ./src/bonus/ft_lstsize.c\
			./printf/src/ft_printf.c ./printf/src/ft_printf_str.c\
			./printf/src/ft_printf_utils.c ./printf/src/ft_printf_hexa.c\
			./printf/src/ft_printf_unsignedint.c ./printf/src/ft_putchar_one.c\
			./printf/src/ft_printf_int_entier.c\
			./GNL/src/get_next_line.c\
			./GNL/src/get_next_line_utils.c
######PRINTF_&&_GNL_PATH######
PRINTF_PATH = /printf
GNL_PATH = /GNL
PRINTF_SRCS = $(wildcard $(PRINTF_PATH)/src/*.c)
GNL_SRC = $(wildcard $(GNL_PATH)/src/*.c)
PRINTF_OBJS = $(patsubst %.c, %.o, $(PRINTF_SRCS))
GNL_OBJS = $(GNL_SRC:.c=.o)
SRCS_OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs
DIRS	= objs

_OBJS = $(SRCS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

CC    =  cc

RM    =  rm -f

RM_DIR =  rm -rf

CFLAGS =  -Wall -Werror -Wextra

${OBJS_DIR}/%.o: ${PRINTF_PATH}/%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@

${OBJS_DIR}/%.o: ${GNL_PATH}/%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@

${OBJS_DIR}/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${_OBJS}
			ar rc ${NAME} ${_OBJS}
			ranlib ${NAME}

all:   ${NAME}

cmain:  ${NAME}
			@${CC} ${CFLAGS} main.c ${NAME}

clean:
		${RM} ${_OBJS}
		${RM_DIR} ${DIRS}
			

fclean: clean
			${RM} ${NAME}
			${RM} ${PNAME}

re:    fclean all

.PHONY: all clean fclean re
.SILENT: