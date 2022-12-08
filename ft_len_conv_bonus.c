#include "ft_printf_bonus.h"

t_ull   conv_cpp_len(t_conv conv_op, va_list *app)
{
	t_ull	temp_len;

	temp_len = 1;
	if (conv_op.speci == 'c')
		va_arg(*app, int);
	else if (conv_op.speci == 'p')
		temp_len = get_itoa_len((t_ull)va_arg(*app, t_ull), \
		"0123456789abcdef") + 2;
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

}

t_ull	conv_u_len(t_conv conv_op, va_list *app)
{
	t_ull	temp_len;
}

t_ull	conv_xs_len(t_conv conv_op, va_list *app)
{
	
}