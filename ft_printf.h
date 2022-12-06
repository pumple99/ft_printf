#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define ERR_MALLOC -1
# define ERR_RETURN_OVER -1
# define ERR_WIDTH_OVER -1
# define ERR_PRECISION_OVER -1
# define ERR_WRITE -1

typedef unsigned long long	t_ull;


//ft_printf.c
int		ft_printf(const char *format, ...);

//ft_len.c
t_ull	get_plain_len(const char **format);


#endif
