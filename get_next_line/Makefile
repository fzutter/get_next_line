# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 10:18:33 by fzutter           #+#    #+#              #
#    Updated: 2024/04/09 15:23:26 by fzutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCR = get_next_line.c get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c

all : $(NAME)

$(NAME) : $(OBJ) get_next_line.h
		ar rcs $(NAME) $(OBJ)

clean :
		rm -rf $(OBJ)

fclean :
		rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re