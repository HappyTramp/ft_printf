#include <stdlib.h>
#include "header.h"

#define STRRCHR_CONVERSIONS(c) (ft_strrchr(CONVERSIONS_STR, c))

/*
** %(?:\d+\$)?[-]?(?:[0]|'.{1})?-?\d*(?:\.\d+)?[cdusxX]
*/

#include <stdio.h>
t_list			*parse(const char *format)
{
	t_list		*format_list;
	t_list		*tmp;
	t_pformat	*parsed;

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
			return (list_destroy(format_list));
		if ((tmp = list_new(parsed)) == NULL)
			return (list_destroy(format_list));
		list_push_back(&format_list, tmp);
	}
	return (format_list);
}

char		*isolate_conversion(const char *conversion_start)
{
	int i;

	i = 0;
	while (strrchr_index(CONVERSIONS_STR, conversion_start[i]) == -1)
		i++;
	return (ft_strndup(conversion_start, i + 1));
}

t_pformat	*parse_reduced(char *fmt)
{
	t_pformat	*pformat;

	if (fmt == NULL)
		return (NULL);
	if ((pformat = (t_pformat*)malloc(sizeof(t_pformat))) == NULL)
		return (NULL);
	pformat->ap_index = -1;
	pformat->left_adjusted = FALSE;
	pformat->zero_padding = FALSE;
	pformat->min_width.wildcard.exist = FALSE;
	pformat->precision.wildcard.exist = FALSE;
	pformat->precision.value = -1;
	pformat->len = ft_strlen(fmt);
	pformat->conversion = strrchr_index(CONVERSIONS_STR, fmt[pformat->len - 1]);
	fmt[pformat->len - 1] = 0;
	fmt = extract_standalone_flags(pformat, fmt);
	fmt = extract_min_width(pformat, fmt);
	fmt = extract_precision(pformat, fmt);
	return (pformat);
}
