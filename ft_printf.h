#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define PUTXNBR(nb) (ft_putxnbr(nb, "0123456789abcdef"))
#define PUTXMAJNBR(nb) (ft_putxnbr(nb, "0123456789ABCDEF"))

/*
** ft_printf.c
*/

int ft_printf(const char *format, ...);

/*
** utils.c
*/

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putxnbr(unsigned int n, char *hex_symbols);
void	ft_putunbr(unsigned int n);

#endif
