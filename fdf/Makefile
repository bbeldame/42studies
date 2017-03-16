# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 19:07:01 by bbeldame          #+#    #+#              #
#    Updated: 2017/03/16 20:49:42 by bbeldame         ###   ########.fr        #
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

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR)/,$(SRCS_NAME))

all: $(NAME)

$(NAME):
	@mkdir -p $(OBJDIR)
	@make -C ./libft
	@gcc $(FLAGS) $(LINKS) -I $(INCDIR) -o $(NAME) $(SRCS) $(LIBFT)
	@echo "$(GREEN)-----------FdF compiled-----------$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C ./libft

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "$(GREEN)------FdF removed completely------$(NC)"

re: fclean all
