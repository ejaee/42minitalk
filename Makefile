# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 13:13:46 by chanwjeo          #+#    #+#              #
#    Updated: 2022/12/29 11:54:42 by ejachoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
NAME_S_BONUS = server_bonus
NAME_C_BONUS = client_bonus

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

LIB_DIR		= ./libft/

DEFS = minitalk.h color.h

LIB_NAME	=	./libft/libft.a

SRC	=	utils.c
OBJ	=	$(SOURCE:.c=.o)

LIBS	=	$(addprefix $(LIB_DIR), $(LIB_NAME))

all: $(NAME_S) $(NAME_C)
$(NAME_S) : server.c  $(DEFS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) server.c $(SRC) -o $(NAME_S) -L $(LIB_DIR) -lft
$(NAME_C) : client.c $(DEFS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) client.c $(SRC) -o $(NAME_C) -L $(LIB_DIR) -lft

bonus: $(NAME_S_BONUS) $(NAME_C_BONUS)
$(NAME_S_BONUS) : server_bonus.c $(DEFS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) server_bonus.c $(SRC) -o $(NAME_S_BONUS) -L $(LIB_DIR) -lft
$(NAME_C_BONUS) : client_bonus.c $(DEFS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) client_bonus.c $(SRC) -o $(NAME_C_BONUS) -L $(LIB_DIR) -lft

clean:
	make -C $(LIB_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME_S) $(NAME_C) $(NAME_S_BONUS) $(NAME_C_BONUS)

re: fclean all bonus

.PHONY:		all clean fclean bonus re
