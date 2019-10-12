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
