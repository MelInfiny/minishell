NAME		=	minishell

SRCS_FOLDER	=	srcs
OBJS_FOLDER	=	objs
INC_FOLDER	=	includes
LIB_FOLDER	=	libft

CC		:=	cc
CFLAGS		:=	-Werror -Wextra -Wall -I$(INC_FOLDER) -I$(LIB_FOLDER)
LDFLAGS		:=	-fsanitize=address -g -fsanitize=leak
VFLAGS		:=	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=helgrind

SRCS_BASE	=	\
			ft_init		\
			ft_free		\
			lexer		\
			parser		\
			ast		\
			ft_str		\
			ft_strd		\
			ft_map		\
			ft_echo		\
			ft_pwd		\
			ft_env		\
			ft_unset	\
			ft_exec		\
			tester		\
			
SRCS		=	$(addsuffix .c, $(addprefix $(SRCS_FOLDER)/, $(SRCS_BASE)))
OBJS		=	$(addsuffix .o, $(addprefix $(OBJS_FOLDER)/, $(SRCS_BASE)))

$(OBJS_FOLDER)/%.o:		$(SRCS_FOLDER)/%.c
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):			$(OBJS)
				make -C $(LIB_FOLDER) --silent
				$(CC)  -o $(NAME) $(OBJS) -lreadline -L $(LIB_FOLDER) -lft

valgrind:
		valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline_leaks ./$(NAME)

clean:
		make -C $(LIB_FOLDER) clean --silent
		rm -rf $(OBJS_FOLDER)

fclean:		clean
		make -C $(LIB_FOLDER)	fclean --silent
		rm -f $(NAME)

all:		$(NAME)

re:		fclean
		$(MAKE) all

.PHONY:		re fclean clean all
