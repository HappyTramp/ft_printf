#include <stdlib.h>
#include "header.h"

#define STRRCHR_CONVERSIONS(c) (ft_strrchr(CONVERSIONS_STR, c))

/*
** %(?:\d+\$)?[-]?(?:[0]|'.{1})?-?\d*(?:\.\d+)?[cdusxX]
*/

#include <stdio.h>
t_flist				*parse(const char *format)
{
	t_flist	*format_list;
	t_flist	*tmp;
	t_pformat		*parsed;

	format_list = NULL;
	while (*format)
	{
		if (*format != '%')
		{
			format++;
			continue;
		}
		format++;
		if ((parsed = parse_reduced(isolate_conversion(format))) == NULL)
			return (list_destroy(&format_list));
		if ((tmp = list_new(parsed)) == NULL)
			return (list_destroy(&format_list));
		list_push_front(&format_list, tmp);
	}
	list_reverse(&format_list);
	return (format_list);
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
	pformat->left_adjusted = FALSE;
	pformat->zero_padding = FALSE;
	pformat->precision.value = -1;
	pformat->precision.wildcard = FALSE;
	pformat->min_width.value = -1;
	pformat->min_width.wildcard = FALSE;
	pformat->len = ft_strlen(fmt);
	pformat->conversion = strrchr_index(CONVERSIONS_STR, fmt[pformat->len - 1]);
	fmt[pformat->len - 1] = '\0';
	fmt = extract_standalone_flags(pformat, fmt + i);
	fmt = extract_min_width(pformat, fmt + i);
	fmt = extract_precision(pformat, fmt + i);
	return (pformat);
}
