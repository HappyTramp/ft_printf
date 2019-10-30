#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

char	*convert_int(va_list ap, t_pformat *pformat)
{
	char *tmp;
	int is_neg;
	long long int n;

	if (pformat->flags & FLAG_SHORT)
		n = va_arg(ap, int);
	else if (pformat->flags & FLAG_SHORT_SHORT)
		n = va_arg(ap, int);
	else if (pformat->flags & FLAG_LONG)
		n = va_arg(ap, long int);
	else if (pformat->flags & FLAG_LONG_LONG)
		n = va_arg(ap, long long int);
	else
		n = va_arg(ap, int);

	is_neg = n < 0;
	char *str = ITOA_DEC(n);
	if (is_neg)
		ft_strcpy(str, str + 1);
	str = handle_precision(pformat, str);
	if (pformat->flags & FLAG_ZERO_PADDING)
	{
		if (is_neg || pformat->flags & FLAG_SIGNED || pformat->flags & FLAG_SPACE)
			pformat->min_width--;
		/* pformat->min_width--; */
		str = handle_padding(pformat, str);
	}
	if (is_neg)
		tmp = ft_strjoin("-", str);
	else if (pformat->flags & FLAG_SIGNED || pformat->flags & FLAG_SPACE)
		tmp = ft_strjoin(pformat->flags & FLAG_SPACE ? " " : "+", str);
	else
		tmp = ft_strdup(str);
	free(str);
	str = tmp;
	if (!(pformat->flags & FLAG_ZERO_PADDING))
		str = handle_padding(pformat, str);
	return (str);
}
