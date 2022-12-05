#include "ft_printf.h"

void	width_flag(t_conv conv_option, char **str, int *err)
{
	char	*c;
	
	c = ' ';
	if (ft_strlen(*str) < conv_option.width)
	{
		if (conv_option.minus)
		{
			
		}
		else if (conv_option.zero && !conv_option.point)
			c = '0';
	}
}
