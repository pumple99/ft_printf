# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2022/12/12 16:56:44 by seunghoy         ###   ########.fr        #
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

SRCS_B = ft_copy_bonus.c \
		 ft_copy_conv2_bonus.c \
		 ft_copy_conv_bonus.c \
		 ft_len_bonus.c \
		 ft_len_conv_bonus.c \
		 ft_parse_bonus.c \
		 ft_printf_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(LIB) $(OBJS)
	ar -rcs $(NAME) $(OBJS) 
	rm -f bonus
	touch all

$(NAME) : all

bonus : $(LIB) $(OBJS_B)
	ar -rcs $(NAME) $(OBJS_B)
	rm -f all
	touch bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)
	cp $(LIB) $(NAME)


clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS) $(OBJS_B) all bonus $(LIB)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re
