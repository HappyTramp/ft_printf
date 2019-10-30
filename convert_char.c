#include <stdarg.h>
#include <stdlib.h>
#include "header.h"

char	*convert_char(va_list ap, t_pformat *pformat)
{
	char *str = ft_strnew(2);
	if (str == NULL)
		return (NULL);
	str[0] = va_arg(ap, int);
	str[1] = '\0';

	/* str = handle_padding(pformat, str); */
	pformat->size = 1;//ft_strlen(str);
	/* return (str); */
	char *tmp;
	int i;
	if (1 >= pformat->min_width)
		return (str);
	if ((tmp = (char*)malloc(sizeof(char) * (pformat->min_width + 1))) == NULL)
		return (NULL);
	if (pformat->flags & FLAG_LEFT_ADJUSTED)
	{
		i = 1;
		ft_memcpy(tmp, str, 2);
		while (i < pformat->min_width)
			tmp[i++] = ' ';
		tmp[i] = 0;
	}
	else
	{
		i = 0;
		while (i <= pformat->min_width - 1)
			tmp[i++] = pformat->flags & FLAG_ZERO_PADDING ? '0' : ' ';
		ft_memcpy(tmp + i - 1, str, 2);
	}
	free(str);
	pformat->size = pformat->min_width;
	return (tmp);
	return (str);
}
