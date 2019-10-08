#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    int i;
    va_list ap;

    va_start(ap, format);
    i = -1;
    while (format[++i])
    {
        if (format[i] == '%')
        {
            switch (format[++i])
            {
                case 'c':
                    ft_putchar(va_arg(ap, char));
                    break;
                case 's':
                    ft_putstr(va_arg(ap, char*));
                    break;
                case 'p':
                    print_addr(va_arg(ap, void*));
                    break;
                case 'd':
                    ft_putnbr(va_arg(ap, int));
                    break;
                case 'i':
                    ft_putnbr(va_arg(ap, int));
                    break;
                case 'u':
                    ft_putunbr(va_arg(ap, unsigned int));
                    break;
                case 'x':
                    ft_putxnbr(va_arg(ap, int));
                    break;
                case 'X':
                    break;
            }
        }
        else
            write(STDOUT_FILENO, format + i, 1);
    }
    va_end(ap);
    return (0);
}

int main()
{
    ft_printf("bonjour\n");
    return 0;
}
