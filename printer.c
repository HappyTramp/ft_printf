#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

#define ITOA_DEC(x) (ft_itoa_base(x, "0123456789"))
#define ITOA_HEX_LOWER(x) (ft_itoa_base(x, "abcdef0123456789"))
#define ITOA_HEX_UPPER(x) (ft_itoa_base(x, "ABCDEF0123456789"))

void	ft_putstr(char *str)
{
	while (*str)
		write(STDOUT_FILENO, str++, 1);
}

int	nbrlen_radix(int nbr, int radix)
{
	int				counter;
	unsigned int	u_nbr;

	if (nbr == 0)
		return (1);
	counter = 0;
	u_nbr = nbr;
	if (nbr < 0)
	{
		counter++;
		u_nbr = -nbr;
	}
	while (u_nbr > 0)
	{
		u_nbr /= radix;
		counter++;
	}
	return (counter);
}

char		*ft_itoa_base(int n, char *base)
{
	char			*str;
	int				len;
	int				is_negative;
	int				radix;
	unsigned int	u_nbr;


	radix = ft_strlen(base);
	len = nbrlen_radix(n, radix);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	is_negative = 0;
	u_nbr = n;
	if (n < 0)
	{
		is_negative = 1;
		str[0] = '-';
		u_nbr = -n;
	}
	len--;
	while (len >= (is_negative ? 1 : 0))
	{
		str[len] = base[u_nbr % radix];
		u_nbr /= radix;
		len--;
	}
	return (str);
}

char	*ft_strnew(int size)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	str[size] = '\0';
	while (size-- > 0)
		str[size] = '\0';
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*clone;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	if ((clone = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		clone[i] = s[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*convert_to_str(t_pformat *pformat, va_list ap)
{
	char	*str;
	t_conversion conversion = pformat->conversion;

	str = NULL;
	if (pformat->min_field_width_wildcard)
		pformat->min_field_width = va_arg(ap, int);
	if (pformat->precision_wildcard)
		pformat->precision = va_arg(ap, int);
	/* printf("\n%d\n", pformat->precision); */
	/* pformat->precision = 45; */
	if (conversion == CONVERSION_CHAR)
	{
		if ((str = ft_strnew(2)) == NULL)
			return (NULL);
		str[0] = (char)va_arg(ap, int);
	}
	else if (conversion == CONVERSION_STR)
		str = ft_strdup(va_arg(ap, char*));
	else if (conversion == CONVERSION_PTR)
		str = ITOA_HEX_UPPER(va_arg(ap, int));
	else if (conversion == CONVERSION_DECIMAL || conversion == CONVERSION_INT)
		str = ITOA_DEC(va_arg(ap, int));
	else if (conversion == CONVERSION_UINT)
		str = ITOA_DEC(va_arg(ap, int));
	else if (conversion == CONVERSION_HEX_LOWER)
		str = ITOA_HEX_LOWER(va_arg(ap, int));
	else if (conversion == CONVERSION_HEX_UPPER)
		str = ITOA_HEX_UPPER(va_arg(ap, int));
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

	if (pformat->min_field_width == -1)
		return;
	if ((len = ft_strlen(str)) >= pformat->min_field_width)
		return;
	tmp = (char*)malloc(sizeof(char) * (pformat->min_field_width + 1));
	if (!pformat->left_adjusted)
	{
		i = 0;
		while (i <= pformat->min_field_width - len)
			tmp[i++] = pformat->zero_padding ? '0' : ' ';
		ft_strcpy(tmp + i - 1, str);
		ft_strcpy(str, tmp);
	}
	else
	{
		ft_strcpy(tmp, str);
		i = len;
		while (i < pformat->min_field_width)
			tmp[i++] = ' ';
		ft_strcpy(str, tmp);
	}
	free(tmp);
}

void	handle_precision(t_pformat *pformat, char *str)
{
	int	len;
	char			*tmp;
	t_conversion	conv;

	if (pformat->precision == -1)
		return ;
	len = ft_strlen(str);
	conv = pformat->conversion;
	if (conv == CONVERSION_STR)
		str[pformat->precision] = '\0';
	else if (conv == CONVERSION_DECIMAL || conv == CONVERSION_INT
				|| conv == CONVERSION_UINT || conv == CONVERSION_HEX_LOWER
				|| conv == CONVERSION_HEX_UPPER)
	{
		if (len >= pformat->precision)
			return ;
		tmp = (char*)malloc(sizeof(char) * (pformat->precision + 1));
		ft_strcpy(tmp + pformat->precision - len, str);
		/* printf("\n>%s< %d %d\n", str, len, pformat->precision); */
		pformat->precision -= len;
		while (pformat->precision-- > 0)
			tmp[pformat->precision] = '0';
		ft_strcpy(str, tmp);
		free(tmp);
	}
}
