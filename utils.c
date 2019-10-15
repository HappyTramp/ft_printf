#include <stdlib.h>
#include "header.h"

#define MIN_INT (1 << 31)
#define MAX_INT (~(1 << 31))

static int	precheck(const char **str)
{
	int is_negative;

	while (**str == ' ' || **str == '\t' || **str == '\n'
			|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	is_negative = 0;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			is_negative = 1;
		(*str)++;
	}
	return (is_negative);
}

int			ft_atoi(const char *str)
{
	unsigned int	nb;
	int				i;
	int				is_negative;

	is_negative = precheck(&str);
	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!is_negative && nb > (unsigned int)MAX_INT)
			return (-1);
		else if (nb > (unsigned int)MIN_INT)
			return (0);
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return ((int)(is_negative ? -nb : nb));
}

char	*ft_strndup(const char *s1, int n)
{
	char	*clone;
	int	i;

	if ((clone = (char*)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		clone[i] = s1[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s) - 1;
	while (s[i] != (char)c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return ((char*)s + i);
}

int		strrchr_index(const char *s, char c)
{
	int i;

	i = ft_strlen((char*)s) - 1;
	while (s[i] != c)
	{
		if (i == 0)
			return (-1);
		i--;
	}
	return (i);

}

int		ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

t_bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	nbrlen_radix(long int nbr, int radix)
{
	int				counter;
	long unsigned int	u_nbr;

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

char		*ft_itoa_base(long int n, char *base)
{
	char			*str;
	int				len;
	int				is_negative;
	int				radix;
	long unsigned int	u_nbr;


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

