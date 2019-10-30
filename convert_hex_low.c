#include <stdarg.h>
#include <stdlib.h>
#include "header.h"

char	*convert_hex_low(va_list ap, t_pformat *pformat)
{
	long long unsigned int n;

	if (pformat->flags & FLAG_SHORT)
		n = va_arg(ap, int);
	else if (pformat->flags & FLAG_SHORT_SHORT)
		n = va_arg(ap, int);
	else if (pformat->flags & FLAG_LONG)
		n = va_arg(ap, long unsigned int);
	else if (pformat->flags & FLAG_LONG_LONG)
		n = va_arg(ap, long long unsigned int);
	else
		n = va_arg(ap, unsigned int);

	char *str = ITOA_HEX_LOW(n);
	str = handle_precision(pformat, str);
	if (pformat->flags & FLAG_ZERO_PADDING)
	{
		if (pformat->flags & FLAG_ALTERNATE && n != 0)
			pformat->min_width -= 2;
		str = handle_padding(pformat, str);
	}
	if (pformat->flags & FLAG_ALTERNATE && n != 0)
	{
		char *tmp = ft_strjoin("0x", str);
		free(str);
		str = tmp;
	}
	if (!(pformat->flags & FLAG_ZERO_PADDING))
		str = handle_padding(pformat, str);
	return (str);
}
