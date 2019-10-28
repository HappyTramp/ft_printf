#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

#define ITOA_DEC(x) (ft_itoa_base(x, "0123456789"))
#define ITOA_HEX_LOWER(x) (ft_itoa_base(x, "0123456789abcdef"))
#define ITOA_HEX_UPPER(x) (ft_itoa_base(x, "0123456789ABCDEF"))

char	*convert_to_str(t_pformat *pformat, va_list ap)
{
	char	*str;
	t_conversion conversion = pformat->conversion;

	str = NULL;
	if (pformat->min_width.wildcard)
	{
		pformat->min_width.value = va_arg(ap, int);
		if (pformat->min_width.value < 0)
		{
			pformat->left_adjusted = TRUE;
			pformat->min_width.value *= -1;
		}
	}
	if (pformat->precision.wildcard)
		pformat->precision.value = va_arg(ap, int);
	if (conversion == CONVERSION_CHAR)
	{
		if ((str = ft_strnew(2)) == NULL)
			return (NULL);
		str[0] = (char)va_arg(ap, int);
	}
	else if (conversion == CONVERSION_STR)
		str = ft_strdup(va_arg(ap, char*));
	else if (conversion == CONVERSION_PTR)
	{
		// handle 0x with and without zero padding
		ft_putstr("0x");
		str = ft_strnew(2);
		str[0] = 'b';
		str[1] = 0;
		str = ITOA_HEX_LOWER((long int)va_arg(ap, void*));
	}
	else if (conversion == CONVERSION_DECIMAL || conversion == CONVERSION_INT)
		str = ITOA_DEC(va_arg(ap, int));
	else if (conversion == CONVERSION_UINT)
		str = ITOA_DEC(va_arg(ap, unsigned int));
	else if (conversion == CONVERSION_HEX_LOWER)
		str = ITOA_HEX_LOWER(va_arg(ap, unsigned int));
	else if (conversion == CONVERSION_HEX_UPPER)
		str = ITOA_HEX_UPPER(va_arg(ap, unsigned int));
	else if (conversion == CONVERSION_PERCENT)
	{
		if ((str = ft_strnew(2)) == NULL)
			return (NULL);
		str[0] = '%';
	}
	handle_precision(pformat, str);
	handle_padding(pformat, str);
	return (str);
}

void	handle_padding(t_pformat *pformat, char *str)
{
	char	*tmp;
	int		len;
	int		i;

	if (pformat->min_width.value == -1)
		return;
	if ((len = ft_strlen(str)) >= pformat->min_width.value)
		return;
	tmp = (char*)malloc(sizeof(char) * (pformat->min_width.value + 1));
	if (!pformat->left_adjusted)
	{
		i = 0;
		while (i <= pformat->min_width.value - len)
			tmp[i++] = pformat->zero_padding ? '0' : ' ';
		ft_strcpy(tmp + i - 1, str);
		ft_strcpy(str, tmp);
	}
	else
	{
		ft_strcpy(tmp, str);
		i = len;
		while (i < pformat->min_width.value)
			tmp[i++] = ' ';
		ft_strcpy(str, tmp);
	}
	free(tmp);
}

/* #include <stdio.h> */
void	handle_precision(t_pformat *pformat, char *str)
{
	int	len;
	char			*tmp;
	t_conversion	conv;

	/* printf("\n%d\n", pformat->precision.value); */
	if (pformat->precision.value == -1)
		return ;
	len = ft_strlen(str);
	conv = pformat->conversion;
	if (conv == CONVERSION_STR)
		str[pformat->precision.value] = '\0';
	else if (conv == CONVERSION_DECIMAL || conv == CONVERSION_INT
				|| conv == CONVERSION_UINT || conv == CONVERSION_HEX_LOWER
				|| conv == CONVERSION_HEX_UPPER)
	{
		if (len >= pformat->precision.value)
			return ;
		tmp = (char*)malloc(sizeof(char) * (pformat->precision.value + 1));
		ft_strcpy(tmp + pformat->precision.value - len, str);
		/* printf("\n>%s< %d %d\n", str, len, pformat->precision); */
		pformat->precision.value -= len;
		while (pformat->precision.value-- > 0)
			tmp[pformat->precision.value] = '0';
		ft_strcpy(str, tmp);
		free(tmp);
	}
}
