#include <stdarg.h>
#include "header.h"

char	*convert_hex_low(va_list ap, t_pformat *pformat)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = ITOA_HEX_LOW(n);
	str = handle_precision(pformat, str);
	if (pformat->flags & FLAG_ALTERNATE && n != 0)
	{
		char *tmp = ft_strjoin("0x", str);
		free(str);
		str = tmp;
	}
	str = handle_padding(pformat, str);
	return (str);
}
