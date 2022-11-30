# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 09:56:34 by psuanpro          #+#    #+#              #
#    Updated: 2022/11/29 00:50:02 by psuanpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCCHK = ./src/argv.c \
		 ./src/argv_utils.c \
		 ./src/philo.c \
		 ./src/philo_utils.c \
		 ./src/philo_utils_1.c \

SRC = main_bonus.c \
	  $(SRCCHK)

OBJS = $(SRC:.c=.o)
CFLAG = -Wall -Wextra -Werror
CC =  gcc
INLIB = -pthread
COMPILE = echo Philo Compiled...

$(NAME): $(OBJS)
		@$(CC) $(CFLAG) $(INLIB) $(OBJS) -o $(NAME) -g
		@$(COMPILE)

all: $(NAME)

clean:
		@rm -rf $(OBJS)

fclean:clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
