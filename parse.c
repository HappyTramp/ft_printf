/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:11:33 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/29 00:11:50 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

#define STRRCHR_CONVERSIONS(c) (ft_strrchr(CONVERSIONS_STR, c))

/*
** %(?:\d+\$)?[-]?(?:[0]|'.{1})?-?\d*(?:\.\d+)?[cdusxX]
*/

t_flist		*parse(char *format)
{
	t_flist		*format_list;
	t_flist		*tmp;
	t_pformat	*parsed;

	format_list = NULL;
	while (*format)
	{
		format++;
		if (format[-1] != '%')
			continue;
		if ((parsed = parse_reduced(format)) == NULL)
			return (list_destroy(&format_list));
		if ((tmp = list_new(parsed)) == NULL)
			return (list_destroy(&format_list));
		list_push_front(&format_list, tmp);
	}
	return (list_reverse(format_list));
}

t_pformat	*parse_reduced(char *fmt)
{
	t_pformat	*pformat;
	int			i;

	i = 0;
	while (strrchr_index(CONVERSIONS_STR, fmt[i]) == -1)
		i++;
	if ((fmt = ft_strndup(fmt, i + 1)) == NULL)
		return (NULL);
	if ((pformat = (t_pformat*)malloc(sizeof(t_pformat))) == NULL)
		return (NULL);
	pformat->precision = -1;
	pformat->min_width = -1;
	pformat->flags = 0;
	pformat->len = ft_strlen(fmt);
	pformat->conversion = fmt[pformat->len - 1];
	fmt[pformat->len - 1] = '\0';
	fmt = extract_standalone_flags(pformat, fmt);
	fmt = extract_min_width(pformat, fmt);
	fmt = extract_precision(pformat, fmt);
	return (pformat);
}
