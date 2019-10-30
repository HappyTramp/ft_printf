/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:11:33 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/30 23:31:12 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

#define STRRCHR_CONVERSIONS(c) (ft_strrchr(CONVERSIONS_STR, c))

/*
** %(?:\d+\$)?[-]?(?:[0]|'.{1})?-?\d*(?:\.\d+)?[cdusxX]
*/

int			parse(char *format, t_flist **flist)
{
	t_flist		*tmp;
	t_pformat	*parsed;

	*flist = NULL;
	while (*format)
	{
		format++;
		if (format[-1] != '%')
			continue;
		if ((parsed = parse_reduced(format)) == NULL)
			return ((int)list_destroy(flist));
		if ((tmp = list_new(parsed)) == NULL)
			return ((int)list_destroy(flist));
		list_push_front(flist, tmp);
		format += (*flist)->content->fmt_len;
	}
	*flist = list_reverse(*flist);
	return (1);
}

t_pformat	*parse_reduced(char *fmt)
{
	t_pformat	*pformat;
	int			i;
	char		*start;

	i = 0;
	while (strrchr_index(CONVERSIONS_STR, fmt[i]) == -1)
		i++;
	if ((start = ft_strndup(fmt, i + 1)) == NULL)
		return (NULL);
	if ((pformat = (t_pformat*)malloc(sizeof(t_pformat))) == NULL)
		return (NULL);
	fmt = start;
	pformat->precision = -1;
	pformat->min_width = -1;
	pformat->flags = 0;
	pformat->fmt_len = ft_strlen(fmt);
	pformat->type = fmt[pformat->fmt_len - 1];
	fmt[pformat->fmt_len - 1] = '\0';
	fmt = extract_standalone_flags(pformat, fmt);
	fmt = extract_min_width(pformat, fmt);
	fmt = extract_precision(pformat, fmt);
	extract_length_modifier(pformat, fmt);
	free(start);
	return (pformat);
}
