# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 11:36:37 by kkido             #+#    #+#              #
#    Updated: 2025/11/24 17:42:05 by kkido            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := philo
CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := \
	main.c \
	exit.c \
	error_check.c \
	philo_utils.c \
	do_philosopher.c \


OBJS := $(SRCS:.c=.o)



.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation successful."

clean:
	@rm -f $(OBJS)
	@echo "Object files cleaned."

fclean:
	@rm -f $(OBJS) $(NAME)
	@echo "All files cleaned."

re: fclean all
