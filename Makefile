# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2022/12/20 15:59:46 by seunghoy         ###   ########.fr        #
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
DEPS = $(OBJS:.o=.d) $(OBJS_B:.o=.d)

all : $(LIB)
	rm -f $(NAME)
	cp $(LIB) $(NAME)
	make all_temp

all_temp : $(OBJS)
	ar -rcs $(NAME) $(OBJS) 
	rm -f bonus
	touch all

$(NAME) : all

bonus : $(LIB)
	rm -f $(NAME)
	cp $(LIB) $(NAME)
	make bonus_temp

bonus_temp : $(OBJS_B)
	ar -rcs $(NAME) $(OBJS_B)
	rm -f all
	touch bonus

%.o : %.c
	$(CC) $(CFLAGS) -c -I. -MMD $<

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS) $(OBJS_B) all bonus $(LIB) $(DEPS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re :
	make fclean
	make all

ifeq "$(filter clean fclean re,$(MAKECMDGOALS))" ""
-include $(DEPS)
endif

.PHONY : clean fclean re
