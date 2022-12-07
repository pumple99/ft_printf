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
t_ull	get_conv_len(const char **format, va_list *app);

//ft_itoa.c
int     get_itoa_len(t_ull nbr, char *base);
char	*base10(t_ull num, int *err);
char	*base16(t_ull num, int *err);
char	*base16_cap(t_ull num, int *err);

//ft_copy.c
int     copy_plain_str(const char **format, char **temp);
int     copy_conv_str(const char **format, char **temp, va_list *ap);

//ft_conv.c


#endif
