#include <stdarg.h>
#include "header.h"

char	*convert_percent(va_list ap, t_pformat *pformat)
{
	char *str = ft_strdup("%");

	(void)ap;
	str = handle_padding(pformat, str);
	return (str);
}
