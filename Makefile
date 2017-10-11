# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadamant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/09 06:18:48 by sadamant          #+#    #+#              #
#    Updated: 2017/10/05 18:27:25 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline

SRC = main.c ft_getnextline.c

LIB = libft.a

FLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -L. -lft

clean:
		;

fclean: ;

re: fclean all
