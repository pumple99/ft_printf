/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:24:40 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/30 15:52:29 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//need change, not complete
int	join_plain_str(const char **format, char **print_str)
{
	int		err;
	t_ull	plain_len;
	char	*plain_str;
	char	*temp;
	
	plain_len = 0;
	while (**format && **format != '%')
		plain_len++;
	*format = *format + plain_len;
	plain_str = sub();
	temp = *print_str;
	*print_str = join(temp, plain_str);
	free(temp);
	free(plain_str);
	if (*print_str == 0 || plain_str == 0)
		return (ERR_MALLOC);
	return (0);
}
