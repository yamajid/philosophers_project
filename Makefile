# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 22:53:37 by yamajid           #+#    #+#              #
#    Updated: 2023/08/28 23:08:32 by yamajid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra 
DBUILD = build
FILES = main parsing ft_atoi utils philo

OBJS = $(addprefix $(DBUILD)/, $(FILES:=.o))

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(DBUILD)/%.o: %.c philo.h
	@mkdir -p $(DBUILD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(DBUILD)

fclean: clean
	@rm -f $(NAME)

re: fclean all

