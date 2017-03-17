# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/17 19:16:02 by bbeldame          #+#    #+#              #
#    Updated: 2017/03/17 20:59:44 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra #ATTENTION A NE PAS GARDER CA EN PROD
LINKS = -lm -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
OBJDIR = ./obj/
INCDIR = ./includes
SRCDIR = ./srcs
SRCS_NAME = *.c

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR)/,$(SRCS_NAME))

all: $(NAME)

$(NAME):
	@mkdir -p $(OBJDIR)
	@make -C ./libft
	@gcc $(FLAGS) $(LINKS) -I $(INCDIR) -o $(NAME) $(SRCS) $(LIBFT)
	@echo "$(GREEN)---------Fractol compiled---------$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C ./libft

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "$(GREEN)----Fractol removed completely----$(NC)"

re: fclean all
