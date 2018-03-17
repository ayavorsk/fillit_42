#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 16:01:22 by ayavorsk          #+#    #+#              #
#    Updated: 2017/10/24 16:01:22 by ayavorsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

HEAD = fillit.h

SRC = 	main.c \
		ft_del_cut.c \
		ft_pars_list.c \
		ft_set_start.c  \
		ft_set_cord.c \
		ft_right_tetri.c \
		ft_replace_space.c \
		ft_sort_space.c  \
		ft_smart_lstdel.c \
		ft_put_error.c \
		ft_create_map.c \
		ft_new_cord.c \
		ft_arr_del.c \
		ft_mark_x.c \
		ft_mark_y.c

LIBFT = libft/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -lft

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: re all clean fclean
.NOTPARALLEL: all ($NAME) $(MK_LIB) re