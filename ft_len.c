#include "ft_printf.h"

t_ull	get_plain_len(const char **format)
{
	t_ull	pl;
	
	pl = 0;
	while (**format && **format != '%')
	{
		pl++;
		(*format)++;
	}
	return (pl);
}

t_ull	get_conv_len(const char **format, va_list *app, int *err)
{
	t_ull	cl;
	
	cl = 0;
	(*format)++;
	if (**format == 'c' || **format == '%')
		return (1);
	else if (**format == 's')
		return (ft_strlen((char *)va_arg(*app, char *)));
	else if (**format == 'd' || **format == 'i' || **format == 'u')
		return 
}
