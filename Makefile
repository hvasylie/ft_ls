# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:28:56 by hvasylie          #+#    #+#              #
#    Updated: 2019/10/19 23:04:09 by hvasylie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = *.c

OBJECTS = *.o

INCLUDES = libft/libft.a

FLAGS = #-Wall -Werror -Wextra

HEADERS = ft_ls.h



all : $(NAME)

$(NAME) : $(INCLUDES) $(OBJECTS)
		@make -C libft/ re
		gcc $(FLAGS) $(SRCS) -o $(NAME) -I $(HEADERS) -L. $(INCLUDES)

$(OBJECTS): $(INCLUDES)
		gcc $(FLAGS) -c $(SRCS)
$(INCLUDES):
		@make libft

clean :
		-rm -f $(OBJECTS)

fclean : clean
		make fclean -C libft
		-rm -f $(NAME)

re: fclean all