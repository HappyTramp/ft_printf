/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:22:29 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/03 20:13:44 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "header.h"

static char	*handle_padding_char(t_pformat *pformat, char *str)
{
	char	*tmp;
	int		i;

	pformat->size = 1;
	if (1 >= pformat->min_width)
		return (str);
	if ((tmp = (char*)malloc(sizeof(char) * (pformat->min_width + 1))) == NULL)
		return (NULL);
	if (pformat->flags & FLAG_LEFT_ADJUSTED)
	{
		ft_memcpy(tmp, str, (i = 1) + 1);
		while (i < pformat->min_width)
			tmp[i++] = ' ';
		tmp[i] = 0;
	}
	else
	{
		i = 0;
		while (i <= pformat->min_width - 1)
			tmp[i++] = pformat->flags & FLAG_ZERO_PADDING ? '0' : ' ';
		ft_memcpy(tmp + i - 1, str, 2);
	}
	free(str);
	pformat->size = pformat->min_width;
	return (tmp);
}

char		*convert_char(va_list ap, t_pformat *pformat)
{
	char	*str;

	if ((str = ft_strnew(2)) == NULL)
		return (NULL);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (handle_padding_char(pformat, str));
}
