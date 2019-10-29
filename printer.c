/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:19:24 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/29 18:46:48 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

#define ITOA_HEX_LOWER(x) (ft_itoa_base(x, "0123456789abcdef"))
#define ITOA_HEX_UPPER(x) (ft_itoa_base(x, "0123456789ABCDEF"))

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
	if ((str = convert_type(pformat->conversion, ap)) == NULL)
		return (NULL);
	if (pformat->flags & FLAG_SIGNED && (pformat->conversion == 'd' || pformat->conversion == 'i')
		&& str[0] != '-')
	{
		char *tmp = ft_strjoin("+", str);
		free(str);
		str = tmp;
	}
	if ((str = handle_precision(pformat, str)) == NULL)
		return (NULL);
	if (pformat->conversion == 'p')
		if ((str = add_address_prefix(str)) == NULL)
			return (NULL);
	if ((str = handle_padding(pformat, str)) == NULL)
		return (NULL);
	return (str);
}

char	*convert_type(t_conversion conversion, va_list ap)
{
	char	*str;

	str = NULL;
	if (conversion == 'c')
	{
		if ((str = ft_strnew(2)) == NULL)
			return (NULL);
		str[0] = (char)va_arg(ap, int);
	}
	else if (conversion == 's')
	{
		char *tmp = va_arg(ap, char*);
		str = tmp == NULL ? ft_strdup("(null)") : ft_strdup(tmp);
	}
	else if (conversion == 'p')
		str = ITOA_HEX_LOWER((long int)va_arg(ap, void*));
	else if (conversion == 'd' || conversion == 'i')
		str = ft_itoa(va_arg(ap, int));
	else if (conversion == 'u')
		str = ft_itoa(va_arg(ap, unsigned int));
	else if (conversion == 'x')
		str = ITOA_HEX_LOWER(va_arg(ap, unsigned int));
	else if (conversion == 'X')
		str = ITOA_HEX_UPPER(va_arg(ap, unsigned int));
	else if (conversion == '%')
		str = ft_strdup("%");
	return (str);
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
		ft_strcpy(tmp, str);
		i = len;
		while (i < pformat->min_width)
			tmp[i++] = ' ';
		tmp[i] = 0;
		ft_strcpy(str, tmp);
	}
	else
	{
		if (IN_STR("+-", str[0]) && pformat->flags & FLAG_ZERO_PADDING)
		{
			tmp[0] = str[0];
			len--;
			i = 1;
			while (i < pformat->min_width - len)
				tmp[i++] = pformat->flags & FLAG_ZERO_PADDING ? '0' : ' ';
			ft_strcpy(tmp + i , str + 1);
			ft_strcpy(str, tmp);
			free(tmp);
			return (str);
		}
		i = 0;
		while (i <= pformat->min_width - len)
			tmp[i++] = pformat->flags & FLAG_ZERO_PADDING ? '0' : ' ';
		ft_strcpy(tmp + i - 1, str);
		ft_strcpy(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*handle_precision(t_pformat *pformat, char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	if (pformat->precision == 0 && str[0] == '0')
		return (ft_strdup(""));
	if (pformat->conversion == 's' && pformat->precision < len)
		str[pformat->precision] = '\0';
	else if (IN_STR("diuxXp", pformat->conversion) && len < pformat->precision)
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

char	*add_address_prefix(char *addr)
{
	char *tmp;

	if ((tmp = ft_strdup(addr)) == NULL)
		return (NULL);
	if ((addr = ft_strjoin("0x", addr)) == NULL)
		return (NULL);
	free(tmp);
	return (addr);
}
