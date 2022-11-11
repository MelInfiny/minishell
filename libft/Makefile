# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enolbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 17:16:17 by enolbas           #+#    #+#              #
#    Updated: 2022/11/11 21:05:50 by enolbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
	ft_atoi.c 						\
	ft_isascii.c 					\
    ft_memcmp.c   ft_putendl_fd.c	\
	ft_strdup.c   ft_strlen.c   ft_strtrim.c \
	ft_bzero.c    ft_isdigit.c  ft_memcpy.c      ft_putnbr_fd.c   ft_striteri.c  ft_strmapi.c  ft_substr.c \
	ft_calloc.c   ft_isprint.c  ft_memmove.c     ft_putstr_fd.c   ft_strjoin.c   ft_strncmp.c  ft_tolower.c \
	ft_isalnum.c  ft_itoa.c     ft_memset.c      ft_split.c       ft_strlcat.c   ft_strnstr.c  ft_toupper.c \
	ft_isalpha.c  ft_memchr.c   ft_putchar_fd.c  ft_strchr.c      ft_strlcpy.c   ft_strrchr.c	\
	ft_printf.c				\
	ft_nbrlen_base_u.c		\
	ft_putnbr_base_u.c		\
	print_char.c	print_hexa.c	print_nbr.c		print_perc.c	\
	print_str.c		print_ptr.c		print_nbr_u.c					\

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -I.

NAME = libft.a

all: $(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
