# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2022/12/08 15:22:02 by seunghoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Werror -Wall -Wextra
LIB = libft.a
LIB_DIR = ./libft

SRCS = ft_printf.c \
	   ft_len.c \
	   ft_copy.c \
	   ft_copy_conv.c

SRCS_B = 

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(LIB) $(OBJS)
	ar -rcs $(NAME) $(OBJS) 
	rm -f bonus
	touch all

$(NAME) : all

#bonus : $(LIB) $(OBJS) $(OBJS_B)
#	ar -rcs $(NAME) $(OBJS) $(OBJS_B)
#	rm -f all
#	touch bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(NAME)


clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS) $(OBJS_B) all bonus

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re
