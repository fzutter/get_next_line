# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabien <fabien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 10:18:33 by fzutter           #+#    #+#              #
#    Updated: 2024/04/24 21:30:06 by fabien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re