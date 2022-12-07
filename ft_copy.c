#include "ft_printf.h"

int copy_plain_str(const char **format, char **temp)
{
    t_ull   len;

    len = get_plain_len(format);
    ft_memmove(*temp, *format - len, len);
    *temp += len;
    return (0);
}
int copy_conv_str(const char **format, char **temp, va_list *ap)
{
    t_ull   len;
    int     err;
    char    *conv_str;
    va_list cap;

    err = 0;
    va_copy(cap, *ap);
    len = get_conv_len(format, ap);
    conv_str = get_conv_str(*format - 1, *cap);
    if (conv_str == 0)
        err = ERR_MALLOC;
    ft_memmove(*temp, conv_str, len);
    *temp += len;
    free(conv_str);
    va_end(cap);
    return (0);
}

int copy_conv_str(const char **format, char **temp, va_list *ap)
{
    if (**format == 'sq')
		return (copy_s(format, temp, ap));
    else if (**format == 's')
		return (copy_s(format, temp, ap));
    else if (**format == 's')
		return (copy_s(format, temp, ap));
    else if (**format == 's')
		return (copy_s(format, temp, ap));
    else if (**format == 's')
		return (copy_s(format, temp, ap));
    else if (**format == 's')
		return (copy_s(format, temp, ap));
    else if (**format == 's')
		return (copy_s(format, temp, ap));
    else if (**format == 's')
		return (copy_s(format, temp, ap));
    else if (**format == 's')
		return (copy_s(format, temp, ap));

}