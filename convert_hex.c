/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:23:06 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/02 02:09:15 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "header.h"

char	*convert_hex(va_list ap, t_pformat *pformat)
{
	char					*str;
	char					*tmp;
	long long unsigned int	n;

	if (pformat->flags & FLAG_LONG)
		n = va_arg(ap, long unsigned int);
	else if (pformat->flags & FLAG_LONG_LONG)
		n = va_arg(ap, long long unsigned int);
	else
		n = va_arg(ap, unsigned int);
	str = ITOA_HEX_LOW(n);
	if (pformat->type == 'X')
		ft_strtoupper(str);
	str = handle_precision(pformat, str);
	if (pformat->flags & FLAG_ZERO_PADDING)
	{
		if (pformat->flags & FLAG_ALTERNATE && n != 0)
			pformat->min_width -= 2;
		str = handle_padding(pformat, str);
	}
	if (pformat->flags & FLAG_ALTERNATE && n != 0)
	{
		tmp = ft_strjoin(pformat->type == 'X' ? "0X" : "0x", str);
		free(str);
		str = tmp;
	}
	if (!(pformat->flags & FLAG_ZERO_PADDING))
		str = handle_padding(pformat, str);
	return (str);
}
