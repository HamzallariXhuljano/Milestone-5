# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 16:23:55 by xhamzall          #+#    #+#              #
#    Updated: 2025/11/06 17:33:39 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
