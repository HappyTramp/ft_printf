#include <unistd.h>
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
