#include <stdlib.h>
#include "header.h"

#define MIN_INT (1 << 31)
#define MAX_INT (~(1 << 31))

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
