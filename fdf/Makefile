# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 19:07:01 by bbeldame          #+#    #+#              #
#    Updated: 2017/04/13 19:49:22 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
MLX = ./minilibX/
MLX_INC	= -I ./miniLibX
LINKS = -L ./minilibX -lm -lmlx -framework OpenGL -framework AppKit
LIBFTA = libft.a
LIBFTDIR = ./libft
OBJDIR = ./obj/
INCDIR = ./includes
SRCDIR = ./srcs/
SRCS_NAME = bonus.c bonus2.c draw.c hooks.c main.c parse.c rotation.c \
	    line.c utils.c
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LIBFT = $(addprefix $(LIBFTDIR)/,$(LIBFTA))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))

all: $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -I $(MLX) -o $@ -c $<

makelibft:
	@make -C $(LIBFTDIR)

makemlx:
	@make -sC $(MLX)

$(NAME): makelibft makemlx obj $(OBJS)
	@gcc $(OBJS) $(LINKS) $(LIBFT) -lm -o $(NAME)
	@echo "$(GREEN)-----------FdF compiled-----------$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFTDIR)
	@make --silent clean -C $(MLX)

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
	@echo "$(GREEN)------FdF removed completely------$(NC)"

re: fclean all
