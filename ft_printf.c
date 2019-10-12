#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

int ft_printf(const char *format, ...)
{
    int i;
    va_list ap;
	t_list	*format_list;
	t_conversion	conv;

	if ((format_list = parse(format)) == NULL)
		return (-1);
    va_start(ap, format);
    i = -1;
    while (format[++i])
    {
        if (format[i] == '%')
        {
			conv = format_list->data->conversion;
			if (conv == CONVERSION_CHAR)
				ft_putchar(va_arg(ap, char));
			else if (conv == CONVERSION_STR)
				ft_putstr(va_arg(ap, char*));
			else if (conv == CONVERSION_PTR)
			{
				ft_putstr("0x");
				PUTXNBR(va_arg(ap, long unsigned int));
			}
			else if (conv == CONVERSION_DECIMAL || conv == CONVERSION_INT)
				ft_putnbr(va_arg(ap, int));
			else if (conv == CONVERSION_UINT)
				ft_putunbr(va_arg(ap, unsigned int));
			else if (conv == CONVERSION_HEX_LOWER)
				PUTXNBR(va_arg(ap, unsigned int));
			else if (conv == CONVERSION_HEX_UPPER)
				PUTXMAJNBR(va_arg(ap, unsigned int));
			else if (conv == CONVERSION_PERCENT)
				ft_putchar('%');
			i += format_list->data->len;
			list_pop_front(&format_list);
        }
        else
            write(STDOUT_FILENO, format + i, 1);
    }
    va_end(ap);
    return (0);
}

int main()
{
	int test;

    ft_printf("char: %c\n", 'r');
    ft_printf("string: %s\n", "bonjour");
    ft_printf("pointer: %p\n", &test);
    ft_printf("int: %d or %i\n", 45, 54);
    ft_printf("uint: %u\n", 1 << 31);
    ft_printf("hex lower: %x\n", 0xabcf012);
    ft_printf("hex upper: %X\n", 0xabcf012);
    ft_printf("percent: %%\n");

	/* ft_printf("precision %.2d\n", 43); */
	ft_printf("min width %4d\n", 43);
	ft_printf("zero padding %04d\n", 43);
	ft_printf("right adjusted %-4d\n", 43);
    return 0;
}
