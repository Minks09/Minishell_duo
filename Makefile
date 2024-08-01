# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 23:08:02 by nigateau          #+#    #+#              #
#    Updated: 2024/08/01 23:33:31 by racinedelar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//////////////////////////////COLORS/////////////////////////////////////#
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;91m
COLOUR_WHITE=\033[0;37m
COLOUR_YELLOW=\033[0;33m
COLOUR_CYAN=\033[0;36m
COLOUR_END=\033[0m
#//////////////////////////////PROJECT////////////////////////////////////#
NAME 			= minishell
#NOM DU PROJET et de lexecutable#
#//////////////////////////////DIRECTORIES////////////////////////////////#
SRC_PATH 		= 	srcs/

LIB 			= 	includes/Libft

HEADER 			= 	includes

HEADER_LIBFT 	= 	includes/Libft

DEPENDENCIES 	= 	$(HEADER)/minishell.h $(HEADER_LIBFT)/libft.h
#Ci dessus sont definis tous les headers dont depend le projet#
#/////////////////////////////SRCS////////////////////////////////////////
SRCS = 	main.c\
		builtins/builtins.c\
		builtins/echo.c\
		builtins/export.c\
		builtins/ft_cd.c\
		builtins/ft_exit.c\
		builtins/ft_pwd.c\
		builtins/print_env.c\
		builtins/unset.c\
		env/env.c\
		exec/exec.c\
		exec/fork.c\
		exec/path_finder.c\
		exec/pipe.c\
		exec/redir.c\
		lexer/check_prompt.c\
		lexer/env.c\
		lexer/error.c\
		lexer/ft_split.c\
		lexer/heredoc.c\
		lexer/lexer.c\
		lexer/redirection.c\
		lexer/split_command.c\
		lexer/split_pipe.c\
		lexer/token.c\
		lexer/utils.c\
		lexer/utils2.c\
		setup/child_signal.c\
		setup/main_signal.c\
		setup/setup.c\
		utils/error_utils.c\
		utils/free_struct.c

#CI dessus sont definis tous les fichiers sources du projet #
#il faut les lister ici en pensant que le chemin des src est deja /srcs/#
#/////////////////////////////FLAGS///////////////////////////////////////#
RM 				= 	rm -f

CC 				= 	gcc

CFLAGS 			= 	-I$(HEADER) -I$(HEADER_LIBFT) -Wall -Wextra -Werror -fsanitize=address -g
TFLAGS			=	-I$(HEADER) -I$(HEADER_LIBFT)
#CI dessus sont definis les variable utiles a la compilation comme les flags ou certaine commande#
#//////////////////////////OBEJCTS/////////////////////////////////////////#
OBJS 		= $(SRCS:c=o)

OBJS_DIR 	= objs

DIRS		= 	objs\
				objs/builtins\
				objs/exec\
				objs/parser\
				objs/utils\
				objs/utils/linked_list\

_OBJS		= $(addprefix $(OBJS_DIR)/, $(OBJS))
#Ci dessus sont defini des variable nous permettant de manipuler les .o et les avoir tous dans un meme dossier.#
#///////////////////////RULES/////////////////////////////////////////////#
# macOS with Homebrew
ifeq ($(shell uname -s), Darwin)
	READLINE_PATH = /opt/homebrew/opt/readline
	RL_FLAGS = -I$(READLINE_PATH)/include
	RL_LDFLAGS = -L$(READLINE_PATH)/lib -lreadline -lhistory
# Pour 42: 
# READLINE_PATH = $(HOME)/.brew/opt/readline
# CFLAGS += -I $(READLINE_PATH)/include -L$(READLINE_PATH)/lib
endif
#CI dessus est une condition qui permet de compiler le projet sur macos avec homebrew#
#/////////////////////CI dessous sont les regles du makefile/////////////////////#
all: check_lib check_minishell

check_lib:
	@if [ -f libft.a ]; then \
		echo "$(COLOUR_GREEN)libft already compiled.$(COLOUR_END)"; \
	else \
		echo "$(COLOUR_YELLOW)Compiling libft...$(COLOUR_END)"; \
		make -C $(HEADER_LIBFT); \
		cp ./$(HEADER_LIBFT)/libft.a libft.a; \
		echo "$(COLOUR_GREEN)libft compiled.$(COLOUR_END)"; \
	fi

check_minishell: check_lib
	@if [ -f $(NAME) ]; then \
		echo "$(COLOUR_GREEN)minishell already compiled.$(COLOUR_END)"; \
		else \
		echo "$(COLOUR_YELLOW)Compiling minishell...$(COLOUR_END)"; \
		$(MAKE) $(NAME); \
	fi

$(NAME): $(_OBJS)
	@$(CC) $(_OBJS) libft.a $(CFLAGS) $(RL_LDFLAGS) -Lincludes/LIBFT -o $@
	@echo "$(COLOUR_GREEN)minishell compiled.$(COLOUR_END)"

$(OBJS_DIR)/%.o: $(SRC_PATH)/%.c $(DEPENDENCIES)
	@mkdir -p $(dir $@)
	@${CC} $(CFLAGS) $(RL_FLAGS) -c $< -o $@ -g3

clean:
	@$(RM) $(OBJS)
	@$(RM) ${_OBJS}
	@$(RM) -r $(OBJS_DIR)
	@$(RM) $(NAME)
	@make fclean -C $(LIB)
	@echo "$(COLOUR_RED)minishell Cleaned$(COLOUR_END)"

fclean: clean
	@$(RM) *.a
	@echo "$(COLOUR_RED)minishell Fcleaned$(COLOUR_END)"
	
test:	$(_OBJS)
	@$(CC) $(_OBJS) libft.a $(TFLAGS) $(RL_LDFLAGS) -Lincludes/LIBFT -o $@
	@echo "$(COLOUR_GREEN)minishell compiled.$(COLOUR_END)"
	
stest: check_lib
	@echo "$(COLOUR_YELLOW)Compiling minishell...$(COLOUR_END)"
	@if [ -f $(NAME) ]; then \
		echo "$(COLOUR_GREEN)minishell already compiled.$(COLOUR_END)"; \
		else \
		echo "$(COLOUR_YELLOW)Compiling minishell...$(COLOUR_END)"; \
		$(MAKE) $(TEST); \
	fi
	
re: fclean all

.PHONY: re fclean clean all
.SILENT:
