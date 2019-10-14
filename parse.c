#include <stdlib.h>
#include "header.h"

#define STRRCHR_CONVERSIONS(c) (ft_strrchr(CONVERSIONS_STR, c))
#define IS_STANDALONE_FLAG(c) (c == '0' || c == '-')

/*
** %(?:\d+\$)?[-]?(?:[0]|'.{1})?-?\d*(?:\.\d+)?[cdusxX]
*/

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
		if ((parsed = parse_conversion(isolate_conversion(format))) == NULL)
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


t_pformat	*parse_reduced_fmt(char *fmt)
{
	t_pformat	*pformat;

	if (conversion == NULL)
		return (NULL);
	if ((pformat = (t_pformat*)malloc(sizeof(t_pformat))) == NULL)
		return (NULL);
	pformat->ap_index = -1;
	pformat->left_adjusted = FALSE;
	pformat->zero_padding = FALSE;
	pformat->min_width->wildcard->exist = FALSE;
	pformat->precision->wildcard->exist = FALSE;
	fmt = extrac_ap_index(pformat, fmt);
	fmt = extrac_standalone_flags(pformat, fmt);
	fmt = extract_min_width(pformat, fmt);
	fmt = extract_precision(pformat, fmt);
	return (pformat);
}

// %[position][dollar][flags][width][.precision][length]type
t_pformat	*parse_conversion(char *conversion)
{
	int i;
	char	*start;
	t_pformat	*pformat;

	if (conversion == NULL)
		return (NULL);
	if ((pformat = (t_pformat*)malloc(sizeof(t_pformat))) == NULL)
		return (NULL);
	i = ft_strlen(conversion) - 1;
	pformat->len = i + 1;
	pformat->conversion = strrchr_index(CONVERSIONS_STR, conversion[i]);
	i--;
	if ((conversion = parse_arg_position(conversion, pformat)) == NULL)
		return (NULL);
	start = conversion;
	pformat->zero_padding = FALSE;
	pformat->left_adjusted = FALSE;
	while (IS_STANDALONE_FLAG(*start))
	{
		if (!pformat->zero_padding)
			pformat->zero_padding = *start == '0';
		if (!pformat->left_adjusted)
			pformat->left_adjusted = *start == '-';
		start++;
	}
	pformat->min_field_width_wildcard = FALSE;
	pformat->min_field_width = -1;
	if (*start == '*')
	{
		pformat->min_field_width_wildcard = TRUE;
		start++;
	}
	if (ft_isdigit(*start))
	{
		/* pformat->min_field_width_wildcard = FALSE; */
		pformat->min_field_width = ft_atoi(start);
		while (ft_isdigit(*start))
			start++;
	}
	pformat->precision = -1;
	pformat->precision_wildcard = FALSE;
	if (*start == '.')
	{
		start++;
		if (*start == '*')
			pformat->precision_wildcard = TRUE;
		else
		{
			pformat->precision = ft_atoi(start);
			while (ft_isdigit(*start))
				start++;
		}
	}
	return (pformat);
}

char	*parse_arg_position(char *conversion, t_pformat *pformat)
{
	if (strrchr_index(conversion, '$') != -1)
	{
		if ((pformat->ap_index = ft_atoi(conversion)) == 0)
		{
			free(pformat);
			return (NULL);
		}
		while (ft_isdigit(*conversion))
			conversion++;
		conversion++;
	}
	else
		pformat->ap_index = -1;
	return (conversion);
}
