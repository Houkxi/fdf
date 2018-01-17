# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:58:31 by mmanley           #+#    #+#              #
#    Updated: 2018/01/15 11:07:20 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = includes/

OBJ_PATH = objs/

SRC_PATH = srcs/

SRC_L = lst_ch/

SRC_P = put/

SRC_S = strs/

SRC_M = mems/

RED = $'\x1b[31m'

GREEN = $'\x1b[32m'

SRC = 	ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_lst_print.c\
		ft_lstadd_end.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstmapi.c\
		ft_lstnew.c\
		ft_deltab.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c \
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c \
		ft_newtab.c\
		ft_strdup.c\
		ft_strnew.c\
		ft_strjoin.c\
		ft_strsub.c\
		ft_strsplit.c\
		ft_putchar_fd.c\
		ft_putchar.c\
		ft_putendl_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_putstr_fd.c\
		ft_putstr.c\
		ft_show_tab.c\
		ft_show_tab_int.c\
		ft_occ_counter.c\
		ft_count_btw.c\
		rec_nbr_count.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strdel.c\
		ft_strmap.c\
		ft_strclr.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strtrim.c\
		ft_strmapi.c\
		ft_striter.c\
		ft_striteri.c\
		ft_tabcpy.c\
		ft_tolower.c\
		ft_toupper.c \
		get_next_line.c\

OBJ_NAME =	$(SRC:.c=.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all : $(NAME)

$(OBJ_PATH) :
	@if [ ! -d "$(OBJ_PATH)" ]; then \
	mkdir $(OBJ_PATH);\
	fi

$(OBJS): $(OBJ_PATH)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "${GREEN}Library build finished"

$(OBJ_PATH)%.o: $(SRC_P)%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

$(OBJ_PATH)%.o: $(SRC_L)%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

$(OBJ_PATH)%.o: $(SRC_S)%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

$(OBJ_PATH)%.o: $(SRC_M)%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

clean :
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME)
	@echo "${RED}Wanted files deleted : .a & .o"

re : fclean all
