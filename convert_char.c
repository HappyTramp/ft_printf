#include <stdarg.h>
#include "header.h"

char	*convert_char(va_list ap, t_pformat *pformat)
{
	char *str = ft_strnew(2);
	if (str == NULL)
		return (NULL);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	str = handle_padding(pformat, str);
	return (str);
}
