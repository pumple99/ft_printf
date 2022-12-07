#include "ft_printf.h"

static t_ull	get_slen(int num, char *base)
{
	t_ull		len;
	long long	new_num;

	len = 0;
	new_num = (long long)num;
	if (new_num < 0)
	{
		len += 1;
		new_num *= -1;
	}
	len += (t_ull)get_itoa_len((t_ull)new_num, base);
	return (len);
}

static t_ull	get_ulen(t_ull num, char *base)
{
	return ((t_ull)get_itoa_len(num, base));
}

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

t_ull	get_conv_len(const char **format, va_list *app)
{
	t_ull	cl;
	
	cl = 0;
	(*format)++;
	if (**format == 'c' || **format == '%')
		cl = 1;
	else if (**format == 's')
		cl = ft_strlen((char *)va_arg(*app, char *));
	else if (**format == 'd' || **format == 'i')
		cl = get_slen((int)va_arg(*app, int), "0123456789");
	else if (**format == 'u')
		cl = get_ulen((t_ull)va_arg(*app, unsigned int), "0123456789");
	else if (**format == 'X' || **format == 'x')
		cl = get_ulen((t_ull)va_arg(*app, unsigned int), "0123456789abcdef");
	else if (**format == 'p')
		cl = get_ulen((t_ull)va_arg(*app, t_ull), "0123456789abcdef");
	else
		return (0);
	(*format)++;
	return (cl);
}
