#include <stdlib.h>
#include "header.h"

#define STRRCHR_CONVERSIONS(c) (ft_strrchr(CONVERSIONS_STR, c))

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

t_pformat	*parse_conversion(char *conversion)
{
	int i;
	t_pformat	*pformat;

	if (conversion == NULL)
		return (NULL);
	if ((pformat = (t_pformat*)malloc(sizeof(t_pformat))) == NULL)
		return (NULL);
	i = ft_strlen(conversion) - 1;
	pformat->conversion = strrchr_index(CONVERSIONS_STR, conversion[i]);
	i--;
	pformat->arg_position = 0;
	pformat->left_adjusted = FALSE;
	pformat->zero_padding = FALSE;
	pformat->min_field_width = -1;
	pformat->len = 1;
	return (pformat);
}
