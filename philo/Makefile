# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 11:36:37 by kkido             #+#    #+#              #
#    Updated: 2025/11/28 16:28:45 by kkido            ###   ########.fr        #
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
	philo_utils2.c \
	do_philosopher.c \
	print_fanc.c \


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
