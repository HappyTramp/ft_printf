#include <stdarg.h>
#include "header.h"

char	*convert_str(va_list ap, t_pformat *pformat)
{
	char *str = va_arg(ap, char*);

	str = str == NULL ? ft_strdup("(null)") : ft_strdup(str);

	if (pformat->precision != -1 && pformat->precision < (int)ft_strlen(str))
		str[pformat->precision] = '\0';
	str = handle_padding(pformat, str);

	return (str);
}
