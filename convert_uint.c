#include <stdarg.h>
#include "header.h"

char	*convert_uint(va_list ap, t_pformat *pformat)
{
	unsigned int n;

	if (pformat->flags & FLAG_SHORT)
		n = va_arg(ap, unsigned short);
	else if (pformat->flags & FLAG_SHORT_SHORT)
		n = va_arg(ap, unsigned char);
	else
		n = va_arg(ap, unsigned int);
	char *str = ft_itoa_base(n, "0123456789");
	str = handle_precision(pformat, str);
	str = handle_padding(pformat, str);
	return (str);
}
