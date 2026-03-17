# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 13:27:45 by hsamira           #+#    #+#              #
#    Updated: 2026/03/17 13:05:38 by hsamira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScalarConverter

CXX = c++

CXXFLAG = -Wall -Werror -Wextra -std=c++98 -MMD -MP

SRC =  ScalarConverter.cpp\
       main.cpp

OBJ = $(SRC:.cpp=.o)

DEPS = $(SRC:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

clean: 
	rm -f $(OBJ)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : re all clean fclean
-include $(DEPS)