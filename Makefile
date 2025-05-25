#------------[MANDATORY]
NAME		= minishell
CC			= cc
HEADER		= -I ./include -I $(LIBFT_DIR)/include
#------------[FLAGS]
CFLAGS		= $(DEBUG_FLAGS) $(W_FLAGS) $(ALL_DEBUG)
DEBUG_FLAGS	= -g3 -lreadline
ALL_DEBUG	= 
W_FLAGS		= #-Wall -Wextra -Werror
#------------[LIBRARY]
LIBFT_DIR	= ./lib/KML
LIBFT_FILE	= $(LIBFT_DIR)/kml.a
#------------[OBJECT_AND_SOURCE]
SRC			= $(addprefix srcs/, $(FILE))
OBJ			= $(SRC:.c=.o)
#------------[ROOT_FILES]
FILE		= $(MAIN) $(INIT) $(ENV) $(BUILTIN) $(EXIT) $(PROCESS)
#------------[SUBFILES]
#------------[MAIN]
MAIN			= $(addprefix $(MAIN_PATH)/, $(MAIN_FILE))
MAIN_PATH		= main
MAIN_FILE		= minishell.c get_t.c signal_bind.c
#------------[PARSER]
PARSER			= $(addprefix $(PARSER_PATH)/, $(PARSER_FILE))
PARSER_PATH		= parser
PARSER_FILE		= extract.c extract_utils.c extract_utils2.c 
#------------[PROCESSUTION]
PROCESS			= $(addprefix $(PROCESS_PATH)/, $(PROCESS_FILE)) $(EXEC)
PROCESS_PATH		= process
PROCESS_FILE		= heredoc.c redirect.c clear.c get_t.c process.c builtin_control.c
	#------------[EXECUTION]
	EXEC			= $(addprefix $(EXEC_PATH)/, $(EXEC_FILE))
	EXEC_PATH		= $(PROCESS_PATH)/exec
	EXEC_FILE		= exec.c clear.c access.c
#------------[BUILTIN]
BUILTIN			= $(addprefix $(BUILTIN_PATH)/, $(BUILTIN_FILE))
BUILTIN_PATH	= builtin
BUILTIN_FILE	= ft_chdir.c builtin.c ft_echo.c ft_pwd.c ft_env.c ft_export.c ft_unset.c ft_exit.c
#------------[ENV]
ENV				= $(addprefix $(ENV_PATH)/, $(ENV_FILE))
ENV_PATH		= environment_variables
ENV_FILE		= get_t.c env_new.c init_env.c print_env.c set_env.c add_env.c del_env.c clear_env.c get_value_env.c
#------------[EXIT]
EXIT			= $(addprefix $(EXIT_PATH)/, $(EXIT_FILE))
EXIT_PATH		= exit
EXIT_FILE		= exit.c get_t.c
#------------[STUPID_PARSER]
STUPID_PARSER		= $(addprefix $(STUPID_PARSER_PATH)/, $(STUPID_PARSER_FILE)) $(SYNTAX) $(EXPAND) $(UNQUOTE) $(EXPORT_TO_EXEC)
STUPID_PARSER_PATH	= stupid_parser
STUPID_PARSER_FILE	= parser.c cut_word.c clear.c debug.c
	#------------[SYNTAX]
	SYNTAX				= $(addprefix $(SYNTAX_PATH)/, $(SYNTAX_FILE))
	SYNTAX_PATH			= $(STUPID_PARSER_PATH)/syntax
	SYNTAX_FILE			= check_quote.c check_pipe.c syntax.c check_redirect.c
	#------------[EXPAND]
	EXPAND				= $(addprefix $(EXPAND_PATH)/, $(EXPAND_FILE))
	EXPAND_PATH			= $(STUPID_PARSER_PATH)/expand
	EXPAND_FILE			= clear.c expand.c get_t.c expand_word.c check.c join_line.c
	#------------[UNQUOTE]
	UNQUOTE				= $(addprefix $(UNQUOTE_PATH)/, $(UNQUOTE_FILE))
	UNQUOTE_PATH			= $(STUPID_PARSER_PATH)/unquote
	UNQUOTE_FILE			= checktype.c ft_unquote_lst.c unquote.c debug.c
	#------------[EXPORT_TO_EXEC]
	EXPORT_TO_EXEC				= $(addprefix $(EXPORT_TO_EXEC_PATH)/, $(EXPORT_TO_EXEC_FILE))
	EXPORT_TO_EXEC_PATH			= $(STUPID_PARSER_PATH)/export
	EXPORT_TO_EXEC_FILE			= debug.c export_to_execute.c new_list.c
#------------[PROCESS]
all: lib $(NAME)
$(NAME): $(OBJ) | $(BUILD_DIR)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FILE) $(HEADER) -o $@ -lreadline
		@printf "\033[38;5;46m\033[1m⟪ Complete ⟫\033[0m\n"
%.o: %.c Makefile
	@printf "\033[38;5;226;1m"
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)
	@printf "\033[1A\033[2K"
lib:
	@make -C $(LIBFT_DIR)
clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR)
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
re: fclean all
.PHONY: all clean fclean re lib
