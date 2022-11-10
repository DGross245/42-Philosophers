# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 08:53:45 by dgross            #+#    #+#              #
#    Updated: 2022/11/10 17:11:56 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c utils.c utils2.c create_destroy.c create_destroy2.c death_time.c error.c routine.c functions.c

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=thread

INCLUDES = -I./includes

w = \033[1;97m
g = \033[1;32m
de = \033[0m
r  = \033[0;31m

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

obj/%.o: src/%.c
	@echo "$(g)Compiling $(w)$< ...$(de)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): obj $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) -o $(NAME)
	@echo "$(g)Compiling Done ✔️$(de)"

clean:
	@echo "$(r)Cleaning 🧹 $(w)...$(de)"
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all 

.PHONY: all clean fclean re bonus
