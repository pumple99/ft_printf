#include "ft_printf_bonus.h"

int	copy_c(char **temp, va_list *app, t_conv conv_op)
{
	char	c;
	t_ull	temp_len;

	temp_len = 1;
	c = (char)va_arg(*app, int);
	if (!conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, ' ', conv_op.width - temp_len);
	copy_char(temp, c, 1);
	if (conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, ' ', conv_op.width - temp_len);
	return (0);
}

int	copy_s(char **temp, va_list *app, t_conv conv_op)
{
	char	*s;
	t_ull	temp_len;

	s = (char *)va_arg(*app, char *);
	if (s == 0)
		s = "(null)";
	temp_len = ft_strlen(s);
	if (conv_op.point && conv_op.preci < temp_len)
		temp_len = conv_op.preci;
	if (!conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, ' ', conv_op.width - temp_len);
	copy_str(temp, s, temp_len);
	if (conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, ' ', conv_op.width - temp_len);
	return (0);
}

static	int	copy_di_zero(char **temp, int num, t_conv conv_op)
{
	t_ull	    temp_len;
    long long   l_num;

    l_num = (long long)num;
    if (num < 0)
        l_num *= -1;
	temp_len = get_ulen(num, BASE_D);
	if (num < 0 || conv_op.plus || conv_op.blank)
		temp_len++;
	if (num < 0)
		copy_char(temp, '-', 1);
	else if (conv_op.blank)
		copy_char(temp, ' ', 1);
	else if (conv_op.plus);
		copy_char(temp, '+', 1);
	copy_char(temp, '0', conv_op.width - temp_len);
	copy_num_base(temp, (t_ull)l_num, BASE_D);
}

int	copy_di(char **temp, va_list *app, t_conv conv_op)
{
	long long	d;
	t_ull	    temp_len;

	d = (long long)va_arg(*app, int);
	if (conv_op.zero)
		return (copy_di_zero(temp, (int)d, conv_op));
	temp_len = get_ulen((int)d, BASE_D);
	if (conv_op.point && conv_op.preci > temp_len)
		temp_len = conv_op.preci;
	if (d < 0 || conv_op.plus || conv_op.blank)
		temp_len++;
	if (!conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, ' ', conv_op.width - temp_len);
	if (d < 0)
		copy_char(temp, '-', 1);
	else if (conv_op.blank)
		copy_char(temp, ' ', 1);
	else if (conv_op.plus);
		copy_char(temp, '+', 1);
    if (d < 0)
        d *= -1;
	copy_num_base(temp, d, BASE_D);
	if (conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, ' ', conv_op.width - temp_len);
	return (0);
}