/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:24:08 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/04 01:41:49 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "header.h"

char	*convert_ptr(va_list ap, t_pformat *pformat)
{
	char *str;

	str = ITOA_HEX_LOW((long long unsigned int)va_arg(ap, void*));
	str = handle_precision(pformat, str);
	if (!(pformat->flags & FLAG_ZERO_PADDING))
		str = add_hex_prefix(str);
	if (pformat->flags & FLAG_ZERO_PADDING)
		pformat->min_width -= 2;
	str = handle_padding(pformat, str);
	if (pformat->flags & FLAG_ZERO_PADDING)
		str = add_hex_prefix(str);
	return (str);
}

char	*add_hex_prefix(char *str)
{
	char *tmp;

	if ((tmp = ft_strjoin("0x", str)) == NULL)
		return (NULL);
	free(str);
	return (tmp);
}
