# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 18:54:36 by mmanley           #+#    #+#              #
#    Updated: 2018/01/17 18:13:26 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfdf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

LFLAGS = -lmlx -framework OpenGL -framework AppKit

INC = ../

lib = libft/includes/

SRC_PATH = srcs/

SRC =	clean_board.c\
		draw_lines.c\
		square_creation.c\
		fdf.c\
		spirale_sq_diag.c\
		spirale_square.c\
		line.c\

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
	$(CC) $(LFLAGS) -o mlx $< $(LIB) libft/libft.a libfdf.a && ./mlx

lib :
	@$(MAKE) -C libft

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
