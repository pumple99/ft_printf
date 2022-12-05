#include "ft_printf.h"

char	*converge_format(t_conv conv_option, va_list *ap, int *err)
{
	if (conv_option.specifier == 0)
		return (0);
	else if (conv_option.specifier == 'c')
		return (conv_c(conv_option, ap, err));
	else if (conv_option.specifier == 's')
		return (conv_s(conv_option, ap, err));
	else if (conv_option.specifier == 'p')
		return (conv_p(conv_option, ap, err));
	else if (conv_option.specifier == 'd')
		return (conv_d(conv_option, ap, err));
	else if (conv_option.specifier == 'i')
		return (conv_i(conv_option, ap, err));
	else if (conv_option.specifier == 'u')
		return (conv_u(conv_option, ap, err));
	else if (conv_option.specifier == 'x')
		return (conv_x(conv_option, ap, err));
	else if (conv_option.specifier == 'X')
		return (conv_x_capital(conv_option, ap, err));
	else if (conv_option.specifier == '%')
		return (conv_hash(conv_option, ap, err));
}

char	*conv_c(t_conv conv_option, va_list *ap, int *err)
{
	char	*temp;
	
	temp = 0;
	*err = malloc_set(&temp, (char)va_arg(*ap, int), 2);
	if (*err)
		return (0);
	if (conv_option.width > 1)
		width_flag(conv_option, &temp, err);
	return (temp);
}

char	*conv_s(t_conv conv_option, va_list *ap, int *err)
{
}

char	*conv_p(t_conv conv_option, va_list *ap, int *err)
{
}

char	*conv_d(t_conv conv_option, va_list *ap, int *err)
{
}
