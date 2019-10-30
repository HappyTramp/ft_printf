#include <stdarg.h>
#include "header.h"

char	*convert_hex_up(va_list ap, t_pformat *pformat)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = ITOA_HEX_UP(n);
	str = handle_precision(pformat, str);
	if (pformat->flags & FLAG_ALTERNATE)
	{
		char *tmp = ft_strjoin("0X", str);
		free(str);
		str = tmp;
	}
	str = handle_padding(pformat, str);
	return (str);
}
