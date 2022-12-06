#include "ft_printf.h"

static int	print_pf(char *print_str, int err, t_ull pf_len)
{
	int	re;

	re = 0;
	if (err)
		re = err;
	else
	{
		re = (int)pf_len;
		if (ft_putstr_fd(print_str, 1) == -1)
			re = ERR_WRITE;
	}
	free(print_str);
	return (re);
}

static t_ull	get_pf_len(const char *format, va_list *app, int *err)
{
	t_ull	len;
	va_list	ap;
	
	len = 0;
	va_copy(ap, *app);
	while (*format && *err)
	{
		if (*format != '%')
			len += get_plain_len(&format);
		else
			len += get_conv_len(&format, &ap, err);
	}
	va_end(ap);
	return (len);
}

static char	*get_pf_str(t_ull pf_len, int *err)
{
	char	*pf_str;
	
	if (*err)
		return (0);
	pf_str = malloc(pf_len + 1);
	if (pf_str == 0)
	{
		*err = ERR_MALLOC;
		return (0);
	}
	pf_str[pf_len] = 0;
	return (pf_str);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*print_str;
	int			err;
	t_ull		pf_len;

	err = 0;
	va_start(ap, format);
	pf_len = get_pf_len(format, &ap, &err);
	print_str = get_pf_str(pf_len, &err);
	while (!err && *format)
	{
		if (*format != '%')
			err = copy_plain_str(&format, print_str);
		else
			err = copy_conv_str(&format, &print_str, &ap);
	}
	va_end(ap);
	return (print_pf(print_str, err, pf_len));
}
