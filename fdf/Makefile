# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 19:07:01 by bbeldame          #+#    #+#              #
#    Updated: 2017/01/16 19:07:02 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
LINKS = -lm -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
OBJECTS = *.o
OBJDIR = ./obj/
INCDIR = ./includes/
SRCDIR = ./srcs/
SRCS = $(SRCDIR)*.c
INCS = $(INCDIR)*.h

all: $(NAME)

$(NAME):
	mkdir -p $(OBJDIR)
	make -C ./libft
	gcc $(FLAGS) $(SRCS) $(LINKS) $(LIBFT) -I $(INCS)
clean:
	rm -rf $(OBJDIR)
	make clean -C ./libft
fclean:	clean
	rm -f $(NAME)
	make fclean -C ./libft
re: fclean all
