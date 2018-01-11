# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 18:54:36 by mmanley           #+#    #+#              #
#    Updated: 2018/01/11 19:35:47 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfdf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = ../

SRC_PATH = srcs/

SRC =	clean_board.c\
		draw_lines.c\
		square_creation.c\
		fdf_start.c\

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: $(SRC_PATH)%.c
	@$(CC) -c $(FLAGS) $< -I $(INC)

%.o: %.c
	@$(CC) -c $(FLAGS) $<

run : $(NAME)
	$(CC) $(FLAGS) -o fdf $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
