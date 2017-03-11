# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 19:07:01 by bbeldame          #+#    #+#              #
#    Updated: 2017/03/11 21:06:28 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
LINKS = -lm -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
OBJDIR = ./obj/
INCDIR = ./includes/
SRCDIR = ./srcs/
SRCS =  $(SRCDIR)bonus.c $(SRCDIR)bonus2.c $(SRCDIR)draw.c \
		$(SRCDIR)hooks.c $(SRCDIR)main.c \
	    $(SRCDIR)parse.c $(SRCDIR)rotation.c \
	    $(SRCDIR)line.c $(SRCDIR)utils.c $(SRCDIR)get_next_line.c
INCS = $(INCDIR)fdf.h $(INCDIR)get_next_line.h

all: $(NAME)

$(NAME):
	mkdir -p $(OBJDIR)
	make -C ./libft
	gcc $(FLAGS) $(LINKS) $(SRCS) $(LIBFT) -I $(INCS) -o $(NAME)
clean:
	rm -rf $(OBJDIR)
	make clean -C ./libft
fclean:	clean
	rm -f $(NAME)
	make fclean -C ./libft
re: fclean all
