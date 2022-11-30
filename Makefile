NAME = libftprintf.a
CC = cc
CFLAGS = -Werror -Wall -Wextra
LIB = libft.a
LIB_DIR = ./libft

SRCS = ft_printf.c
SRCS_B = 

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(OBJS) $(LIB)
	ar -rcs $(NAME) $(OBJS)
	rm -f bonus
	touch all

$(NAME) : all

bonus : $(OBJS) $(OBJS_B) $(LIB)
	ar -rcs $(NAME) $(OBJS) $(OBJS_B)
	rm -f all
	touch bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< $(LIB_DIR)/$(LIB)

$(LIB) :
	make -C $(LIB_DIR) all

clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS) $(OBJS_B) all bonus

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re $(LIB)
