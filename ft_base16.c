/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:35:26 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 15:35:40 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_itoa_len(t_ull nbr, char *base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= ft_strlen(base);
		len++;
	}
	return (len);
}

static char	*ft_itoa_base(t_ull nbr, char *base)
{
	int		size;
	char	*return_str;

	size = get_itoa_len(nbr, base);
	return_str = (char *)malloc(size + 1);
	return_str[size--] = 0;
	while (size >= 0)
	{
		return_str[size] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
		size--;
	}
	return (return_str);
}

char	*base16(t_ull num, int *err)
{
	char	*temp;

	temp = ft_itoa_base(num, "0123456789abcdef");
	if (temp == 0)
		*err = ERR_MALLOC;
	return (temp);
}

char	*base16_cap(t_ull num, int *err)
{
	char	*temp;

	temp = ft_itoa_base(num, "0123456789ABCDEF");
	if (temp == 0)
		*err = ERR_MALLOC;
	return (temp);
}
