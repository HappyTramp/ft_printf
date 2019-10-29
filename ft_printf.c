/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:15:28 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/29 05:17:55 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "header.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	t_flist	*format_list;
	char	*str;
	int		print_len;
	int		i;

	str = ft_strdup(format);
	if ((format_list = parse(str)) == NULL)
		return (-1);
	free(str);
	va_start(ap, format);
	print_len = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] != '%')
		{
			write(STDOUT_FILENO, format + i, 1);
			continue ;
		}
		str = convert(format_list->content, ap);
		if (str == NULL)
		{
			list_destroy(&format_list);
			return (-1);
		}
		ft_putstr(str);
		print_len += ft_strlen(str);
		free(str);
		i += format_list->content->len;
		list_pop_front(&format_list);
	}
	list_destroy(&format_list);
	va_end(ap);
	return (print_len + i);
}
