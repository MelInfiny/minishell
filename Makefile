NAME		=	minishell

SRCS_FOLDER	=	srcs
OBJS_FOLDER	=	objs
INC_FOLDER	=	includes
LIB_FOLDER	=	libft
PRINTF_FOLDER = ft_printf

CC		:=	cc
CFLAGS		:=	-Werror -Wextra -Wall -I$(INC_FOLDER) -I$(LIB_FOLDER) -I$(PRINTF_FOLDER)
LDFLAGS		:=	-fsanitize=address -g -fsanitize=leak
VFLAGS		:=	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=helgrind

SRCS_BASE	=	\
			ft_readline	\
			ft_redirect	\
			ft_echo		\
			ft_cd		\
			ft_pwd		\
			tester		\
			
			
SRCS		=	$(addsuffix .c, $(addprefix $(SRCS_FOLDER)/, $(SRCS_BASE)))
OBJS		=	$(addsuffix .o, $(addprefix $(OBJS_FOLDER)/, $(SRCS_BASE)))

$(OBJS_FOLDER)/%.o:		$(SRCS_FOLDER)/%.c
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):			$(OBJS)
				make -C $(LIB_FOLDER) --silent
				make -C $(PRINTF_FOLDER) --silent
				$(CC)  -o $(NAME) $(OBJS) -lreadline -L $(LIB_FOLDER) -lft -L $(PRINTF_FOLDER) -lftprintf

clean:
		make -C $(LIB_FOLDER) clean --silent
		make -C $(PRINTF_FOLDER) clean --silent
		rm -rf $(OBJS_FOLDER)

fclean:		clean
		make -C $(LIB_FOLDER)	fclean --silent
		make -C $(PRINTF_FOLDER)	fclean --silent
		rm $(NAME)

all:		$(NAME)

re:		fclean
		$(MAKE) all

.PHONY:		re fclean clean all
