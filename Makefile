# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: racinedelarbre <racinedelarbre@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 23:08:02 by nigateau          #+#    #+#              #
#    Updated: 2024/07/23 15:13:41 by racinedelar      ###   ########.fr        #
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
		builtins/export.c\
		builtins/unset.c\
		builtins/print_env.c\
		builtins/echo.c\
		builtins/ft_cd.c\
		builtins/ft_exit.c\
		builtins/ft_pwd.c\
		env/env.c\
		env/init.c\
		error/utils_error.c\
		exec/exec.c\
		parsing/lexer/check_prompt.c\
		parsing/lexer/env.c\
		parsing/lexer/heredoc.c\
		parsing/lexer/lexer.c\
		parsing/lexer/split_command.c\
		parsing/lexer/token.c\
		parsing/lexer/utils.c\
		setup/setup.c\
		setup/main_signal.c\
		setup/child_signal.c\
		utils/env_utils.c\
		utils/env_utils2.c\
		utils/free_struct.c
	
		
#CI dessus sont definis tous les fichiers sources du projet #
#il faut les lister ici en pensant que le chemin des src est deja /srcs/#
#/////////////////////////////FLAGS///////////////////////////////////////#
RM 				= 	rm -f

CC 				= 	gcc

CFLAGS 			= 	-I$(HEADER) -I$(HEADER_LIBFT) -Wall -Wextra -Werror -fsanitize=address -g
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
all: $(NAME)
	@echo "$(COLOUR_GREEN)minishell compiled.$(COLOUR_END)";
#CI dessus est la regle par defaut du makefile#
check: 
	@if [ -f $(NAME) ]; then \
		echo "$(COLOUR_GREEN)minishell already compiled.$(COLOUR_END)"; \
		break; \
	else \
		echo "$(COLOUR_YELLOW)minishell not compiled.$(COLOUR_END)"; \
	fi
#CI dessus est une condition qui permet de verifier si le projet est deja compile ou non#

lib : 
	if [ -f libft.a ]; then \
		echo "$(COLOUR_GREEN)libft already compiled.$(COLOUR_END)";\
		exit 0;\
	else\
		echo "$(COLOUR_YELLOW)libft not compiled$(COLOUR_END)";\
		make -C $(HEADER_LIBFT);\
		echo "$(COLOUR_CYAN)Compiling Libft...$(COLOUR_END)";\
		cp ./$(HEADER_LIBFT)/libft.a libft.a;\
		echo "$(COLOUR_GREEN)libft compiled.$(COLOUR_END)";\
	fi

#CI dessus est une condition qui permet de verifier si la libft est deja compilee ou non#
$(NAME): check lib $(_OBJS)
	@echo "$(COLOUR_CYAN)Compiling minishell..."
	@$(CC) $(_OBJS) libft.a $(CFLAGS) $(RL_LDFLAGS) -Lincludes/LIBFT -o $@
#CI dessus est la regle qui permet de compiler le projet#
$(OBJS_DIR)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@${CC} $(CFLAGS) $(RL_FLAGS) -c $< -o $@ -g3
#CI dessus est la regle qui permet de compiler les .o#
clean:
			@$(RM) $(OBS)
			@$(RM) ${_OBJS}
			@$(RM) -r $(OBJS_DIR)
			@$(RM) $(NAME)
			@make fclean -C $(LIB)
			@echo "$(COLOUR_RED)minishell Cleaned$(COLOUR_END)"
#CI dessus est la regle qui permet de supprimer les .o et les .d#
fclean:		clean
			@$(RM) *.a
			@echo "$(COLOUR_RED)minishell Fcleaned$(COLOUR_END)"
#CI dessus est la regle qui permet de supprimer les .o, les .d et l'executable#/
re:			fclean all
#CI dessus est la regle qui permet de supprimer les .o, les .d et l'executable puis de recompiler le projet#
.PHONY: re fclean clean all
#CI dessus sont les regles qui ne sont pas des fichiers#
.SILENT:
# ********************************EOF****************************************** #