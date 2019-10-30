#include <stdarg.h>
#include "header.h"

char	*convert_ptr(va_list ap, t_pformat *pformat)
{
	char *str = ITOA_HEX_LOW(va_arg(ap, void*));

	str = handle_precision(pformat, str);
	str = add_hex_prefix(str);
	str = handle_padding(pformat, str);
	return (str);
}

char	*add_hex_prefix(char *str)
{
	char *tmp;

	if ((tmp = ft_strjoin("0x", str)) == NULL)
		return (NULL);
	free(str);
	return (tmp);
}
