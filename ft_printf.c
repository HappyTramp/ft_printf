/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:15:28 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/06 00:01:32 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	t_flist	*flist;
	char	*str;
	int		print_len;
	int		i;

	if (format == NULL)
		return (-1);
	str = ft_strdup(format);
	if (!parse(str, &flist))
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
			print_len++;
			continue ;
		}
		str = convert(flist->content, ap);
		if (str == NULL && flist->content->specifier == 'n')
		{
			if (flist->content->written != NULL)
				*flist->content->written = print_len;
			i += flist->content->fmt_len;
			list_pop_front(&flist);
			continue;
		}
		if (str == NULL)
		{
			list_destroy(&flist);
			return (-1);
		}
		if (flist->content->specifier == 'c')
		{
			write(1, str, flist->content->size);
			print_len++;
			free(str);
		}
		else
		{
			ft_putstr(str);
			print_len += ft_strlen(str);
			free(str);
		}
		i += flist->content->fmt_len;
		list_pop_front(&flist);
	}
	list_destroy(&flist);
	va_end(ap);
	return (print_len);
}
