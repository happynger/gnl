# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:03:49 by otahirov          #+#    #+#              #
#    Updated: 2018/10/11 19:08:48 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

BIN = *.o

INC = -I./includes

all : $(NAME)

$(NAME) : 
		@gcc -Wall -Werror -Wextra -c $(SRC) $(INC)
		@ar rc $(NAME) $(BIN)
		@ranlib $(NAME)
		@echo "Library Generated!"

clean :
		@rm -f $(BIN)
		@echo "Deleted Object files"

fclean : clean
		@rm -rf $(NAME)
		@echo "Deleted Library"

re : fclean all
