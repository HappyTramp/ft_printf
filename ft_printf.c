/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:15:28 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/30 17:10:32 by cacharle         ###   ########.fr       */
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
			continue ;
		}
		str = convert(flist->content, ap);
		if (str == NULL)
		{
			list_destroy(&flist);
			return (-1);
		}
		if (flist->content->type == 'c')
		{
			write(1, str, flist->content->size);
			/* printf("\n%d\n", flist->content->size); */
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
	return (print_len + i);
}

char	*ft_strappend(char *dest, char *src)
{
	void	*copy;

	if ((copy = (char*)malloc(sizeof(char) * (ft_strlen(dest) + 1))) == NULL)
		return (NULL);
	ft_strcpy(copy, dest);
	free(dest);
	dest = (char*)malloc(sizeof(char) * (ft_strlen(copy) + ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, copy);
	free(copy);
	ft_strcat(dest, src);
	return (dest);
}
