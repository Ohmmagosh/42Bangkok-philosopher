# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 00:54:31 by psuanpro          #+#    #+#              #
#    Updated: 2022/12/05 20:30:47 by psuanpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCCHK = ./src/argv.c \
		 ./src/argv_utils.c \
		 ./src/philo.c \
		 ./src/philo_utils.c \
		 ./src/philo_utils_1.c \
		 ./src/philo_utils_2.c \

SRC = main.c \
	  $(SRCCHK)

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -pthread
CC =  gcc
COMPILE = echo Philo Compiled...

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -g
		@$(COMPILE)

all: $(NAME)

clean:
		@rm -rf $(OBJS)

fclean:clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
