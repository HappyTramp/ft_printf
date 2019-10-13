#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(STDOUT_FILENO, str++, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	p_n;

	p_n = n;
	if (n < 0)
	{
		ft_putchar('-');
		p_n = -n;
	}
	if (p_n > 9)
		ft_putnbr(p_n / 10);
	ft_putchar(p_n % 10 + '0');
}

void	ft_putxnbr(long unsigned int n, char *hex_symbols)
{
	if (n > 15)
		ft_putxnbr(n / 16, hex_symbols);
	ft_putchar(hex_symbols[n % 16]);
}

void	ft_putunbr(unsigned int n)
{
	if (n > 9)
		ft_putunbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	nbrlen(int nbr)
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
		u_nbr /= 10;
		counter++;
	}
	return (counter);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				is_negative;
	unsigned int	u_nbr;

	len = nbrlen(n);
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
		str[len] = u_nbr % 10 + '0';
		u_nbr /= 10;
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
	if (conversion == CONVERSION_CHAR)
	{
		if ((str = ft_strnew(2)) == NULL)
			return (NULL);
		str[0] = (char)va_arg(ap, int);
	}
	else if (conversion == CONVERSION_STR)
		str = ft_strdup(va_arg(ap, char*));
	/* else if (conversion == CONVERSION_PTR) */
	/* { */
	/* 	ft_putstr("0x"); */
	/* 	PUTXNBR(va_arg(ap, long unsigned int)); */
	/* } */
	else if (conversion == CONVERSION_DECIMAL || conversion == CONVERSION_INT)
		str = ft_itoa(va_arg(ap, int));
	/* else if (conversion == CONVERSION_UINT) */
	/* 	ft_putunbr(va_arg(ap, unsigned int)); */
	/* else if (conversion == CONVERSION_HEX_LOWER) */
	/* 	PUTXNBR(va_arg(ap, unsigned int)); */
	/* else if (conversion == CONVERSION_HEX_UPPER) */
	/* 	PUTXMAJNBR(va_arg(ap, unsigned int)); */
	else if (conversion == CONVERSION_PERCENT)
	{
		if ((str = ft_strnew(2)) == NULL)
			return (NULL);
		str[0] = '%';
	}
	add_padding(pformat, str);
	return (str);
}

void	add_padding(t_pformat *pformat, char *str)
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

void	print_conversion(t_conversion conversion, va_list ap)
{
	if (conversion == CONVERSION_CHAR)
		ft_putchar((char)va_arg(ap, int));
	else if (conversion == CONVERSION_STR)
		ft_putstr(va_arg(ap, char*));
	else if (conversion == CONVERSION_PTR)
	{
		ft_putstr("0x");
		PUTXNBR(va_arg(ap, long unsigned int));
	}
	else if (conversion == CONVERSION_DECIMAL || conversion == CONVERSION_INT)
		ft_putnbr(va_arg(ap, int));
	else if (conversion == CONVERSION_UINT)
		ft_putunbr(va_arg(ap, unsigned int));
	else if (conversion == CONVERSION_HEX_LOWER)
		PUTXNBR(va_arg(ap, unsigned int));
	else if (conversion == CONVERSION_HEX_UPPER)
		PUTXMAJNBR(va_arg(ap, unsigned int));
	else if (conversion == CONVERSION_PERCENT)
		ft_putchar('%');
}
