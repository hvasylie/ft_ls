# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 23:34:07 by hvasylie          #+#    #+#              #
#    Updated: 2019/05/17 19:56:32 by hvasylie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILE =	*.c

OBJECT = $(FILE:%.c=%.o)

GCCW = -Wextra -Wall -Werror

DEL = rm -f

all: $(NAME)

$(NAME): 
	gcc -c $(GCCW) $(FILE)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

clean:
	$(DEL) $(OBJECT)

fclean: clean
	$(DEL) $(NAME)

re: fclean all
