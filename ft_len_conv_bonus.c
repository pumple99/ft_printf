#include "ft_printf_bonus.h"

t_ull   conv_cpp_len(t_conv conv_op, va_list *app)
{
	t_ull	temp_len;

	temp_len = 1;
	if (conv_op.speci == 'c')
		va_arg(*app, int);
	else if (conv_op.speci == 'p')
		temp_len = (t_ull)get_itoa_len((t_ull)va_arg(*app, t_ull), \
		BASE_X) + 2;
	if (conv_op.width > temp_len)
		temp_len = conv_op.width;
	return (temp_len);
}

t_ull   conv_s_len(t_conv conv_op, va_list *app)
{
	char	*s;
	t_ull	temp_len;

	s = (char *)va_arg(*app, char *);
	if (s == 0)
		temp_len = 6;
	else
		temp_len = ft_strlen(s);
	if (conv_op.point && conv_op.preci < temp_len)
		temp_len = conv_op.preci;
	if (conv_op.width > temp_len)
		temp_len = conv_op.width;
	return (temp_len);
}

t_ull	conv_di_len(t_conv conv_op, va_list *app)
{
	int		di;
	t_ull	temp_len;
	
	di = (int)va_arg(*app, int);
	temp_len = get_slen(di, BASE_D);
	if (di < 0)
		temp_len--;
	if (conv_op.point && conv_op.preci > temp_len)
		temp_len = conv_op.preci;
	if (di < 0 || conv_op.blank || conv_op.plus)
		temp_len++;
	if (conv_op.width > temp_len)
		temp_len = conv_op.width;
	return (temp_len);
}

t_ull	conv_u_len(t_conv conv_op, va_list *app)
{
	t_ui	u;
	t_ull	temp_len;
	
	u = (t_ui)va_arg(*app, t_ui);
	temp_len = (t_ull)get_itoa_len((t_ull)u, BASE_D);
	if (conv_op.point && conv_op.preci > temp_len)
		temp_len = conv_op.preci;
	if (conv_op.width > temp_len)
		temp_len = conv_op.width;
	return (temp_len);
}

t_ull	conv_xs_len(t_conv conv_op, va_list *app)
{
	t_ull	xs;
	t_ull	temp_len;
	
	xs = (t_ull)(t_ui)va_arg(*app, t_ui);
	temp_len = (t_ull)get_itoa_len(xs, BASE_X);
	if (conv_op.point && conv_op.preci > temp_len)
		temp_len = conv_op.preci;
	if (xs > 0 && conv_op.hash)
		temp_len += 2;
	if (conv_op.width > temp_len)
		temp_len = conv_op.width;
	return (temp_len);
}
