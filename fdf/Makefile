# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 19:07:01 by bbeldame          #+#    #+#              #
#    Updated: 2017/03/12 15:46:50 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
LINKS = -lm -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
OBJDIR = ./obj/
INCDIR = ./includes
SRCDIR = ./srcs
SRCS_NAME =  bonus.c bonus2.c draw.c hooks.c main.c parse.c rotation.c \
	    line.c utils.c get_next_line.c

SRCS = $(addprefix $(SRCDIR)/,$(SRCS_NAME))

all: $(NAME)

$(NAME):
	mkdir -p $(OBJDIR)
	make -C ./libft
	gcc $(FLAGS) $(LINKS) -I $(INCDIR) -o $(NAME) $(SRCS) $(LIBFT)
clean:
	rm -rf $(OBJDIR)
	make clean -C ./libft
fclean:	clean
	rm -f $(NAME)
	make fclean -C ./libft
re: fclean all
