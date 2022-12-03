# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 09:56:34 by psuanpro          #+#    #+#              #
#    Updated: 2022/12/04 02:08:17 by psuanpro         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -pthread
CC =  gcc
# INLIB = -pthread #-fsanitize=address
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
