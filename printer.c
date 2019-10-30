/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:19:24 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/30 04:13:18 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"


char	*convert(t_pformat *pformat, va_list ap)
{
	char			*str;

	if (pformat->flags & FLAG_MIN_WIDTH_WILDCARD)
	{
		if (pformat->flags & FLAG_MIN_WIDTH_OVERWRITE)
			(void)va_arg(ap, int);
		else
			pformat->min_width = va_arg(ap, int);
		if (pformat->min_width < 0)
		{
			pformat->flags |= FLAG_LEFT_ADJUSTED;
			pformat->min_width *= -1;
		}
	}
	if (pformat->flags & FLAG_PRECISION_WILDCARD)
		pformat->precision = va_arg(ap, int);
	if ((str = convert_type(ap, pformat)) == NULL)
		return (NULL);
	return (str);
}

char	*convert_type(va_list ap, t_pformat *pformat)
{
	if (pformat->type == 'c')
		return (convert_char(ap, pformat));
	if (pformat->type == 's')
		return (convert_str(ap, pformat));
	if (pformat->type == 'p')
		return (convert_ptr(ap, pformat));
	if (pformat->type == 'd' || pformat->type == 'i')
		return (convert_int(ap, pformat));
	if (pformat->type == 'u')
		return (convert_uint(ap, pformat));
	if (pformat->type == 'x')
		return (convert_hex_low(ap, pformat));
	if (pformat->type == 'X')
		return (convert_hex_up(ap, pformat));
	if (pformat->type == '%')
		return (convert_percent(ap, pformat));
	return (NULL);
}

char	*handle_padding(t_pformat *pformat, char *str)
{
	char	*tmp;
	int		len;
	int		i;

	if ((len = ft_strlen(str)) >= pformat->min_width)
		return (str);
	if ((tmp = (char*)malloc(sizeof(char) * (pformat->min_width + 1))) == NULL)
		return (NULL);
	if (pformat->flags & FLAG_LEFT_ADJUSTED)
	{
		i = len;
		ft_strcpy(tmp, str);
		while (i < pformat->min_width)
			tmp[i++] = ' ';
		tmp[i] = 0;
	}
	else
	{
		i = 0;
		while (i <= pformat->min_width - len)
			tmp[i++] = pformat->flags & FLAG_ZERO_PADDING ? '0' : ' ';
		ft_strcpy(tmp + i - 1, str);
	}
	free(str);
	return (tmp);
}

/* char *handle_nbr_padding(t_pformat *pformat, char *str) */
/* { */
/* 	char *tmp; */
/* 	int len = ft_strlen(str); */
/* 	int i; */
/*  */
/* 	if (!(IN_STR("+-", str[0]) && pformat->flags & FLAG_ZERO_PADDING)) */
/* 		return (str); */
/* 	tmp[0] = str[0]; */
/* 	len--; */
/* 	i = 1; */
/* 	while (i < pformat->min_width - len) */
/* 		tmp[i++] = '0'; */
/* 	ft_strcpy(tmp + i , str + 1); */
/* 	ft_strcpy(str, tmp); */
/* 	free(tmp); */
/* 	return (str); */
/* } */

char	*handle_precision(t_pformat *pformat, char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	if (pformat->precision == 0 && str[0] == '0')
		return (ft_strdup(""));
	else if (IN_STR("diuxXp", pformat->type) && len < pformat->precision)
	{
		if ((tmp = (char*)malloc(sizeof(char) * (pformat->precision + 1))) == NULL)
			return (NULL);
		if (IN_STR("+-", str[0]))
		{
			tmp[0] = str[0];
			len--;
			ft_strcpy(tmp + pformat->precision - len + 1, str + 1);
			while (pformat->precision-- > len)
				tmp[pformat->precision - len + 1] = '0';
			ft_strcpy(str, tmp);
			free(tmp);
			return (str);
		}
		ft_strcpy(tmp + pformat->precision - len, str);
		while (pformat->precision-- > len)
			tmp[pformat->precision - len] = '0';
		ft_strcpy(str, tmp);
		free(tmp);
	}
	return (str);
}
