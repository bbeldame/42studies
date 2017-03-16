# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 18:06:34 by bbeldame          #+#    #+#              #
#    Updated: 2017/03/16 20:50:14 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

GREEN = \033[0;32m

RED = \033[0;31m

NC = \033[0m

NAME =	libft.a

LIB =	ar rc

RLIB =	ranlib

SRCS =	ft_putchar.c \
		ft_putstr.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_makesentence.c \
		ft_max.c \
		ft_min.c \
		ft_strrev.c \
		ft_recursive_power.c \
		ft_swap.c

OBJS =	$(SRCS:.c=.o)

all: 	$(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS)
	@$(LIB) $(NAME) $(OBJS)
	@$(RLIB) $(NAME)
	@echo "$(GREEN)----------Libft compiled----------$(NC)"

clean:
	@/bin/rm -f $(OBJS)

fclean:	clean
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)-----Libft removed completely-----$(NC)"

re: fclean all

.PHONY: all clean fclean re
