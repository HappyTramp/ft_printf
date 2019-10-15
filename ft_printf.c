#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

int ft_printf(const char *format, ...)
{
    int print_len;
    va_list ap;
	/* va_list ap_start; */
	/* int ap_index; */
	t_list	*format_list;
	char	*str;

	if ((format_list = parse(format)) == NULL)
		return (-1);
	/* ap_index = 0; */
    va_start(ap, format);

	/* va_copy(ap_start, ap); */
    print_len = -1;
    while (format[++print_len])
    {
        if (format[print_len] == '%')
        {
			/* if (format_list->data->ap_index != -1) */
			/* { */
			/* 	ap_index = format_list->data->ap_index; */
			/* } */
			/* else */
			/* 	ap_index++; */
			/* printf("\n%d\n", format_list->data->left_adjusted); */
			/* printf("\n%d\n", format_list->data->precision); */
			/* printf("\n%d\n", format_list->data->precision_wildcard); */
			/* printf("\n%d\n", format_list->data->min_field_width); */
			if ((str = convert_to_str(format_list->data, ap)) == NULL)
				return (-1);
			ft_putstr(str);
			free(str);

			print_len += format_list->data->len;
			list_pop_front(&format_list);
        }
        else
            write(STDOUT_FILENO, format + print_len, 1);
    }
    va_end(ap);
    return (print_len);
}

#ifndef TESTING

int main()
{
	/* int test; */

    /* ft_printf("char: %c\n", 'r'); */
    /* ft_printf("string: %s\n", "bonjour"); */
    /* ft_printf("pointer: %p\n", &test); */
    /* ft_printf("int: %d or %i\n", 45, 54); */
    /* ft_printf("uint: %u\n", 1 << 31); */
    /* ft_printf("hex lower: %x\n", 0xabcf012); */
    /* ft_printf("hex upper: %X\n", 0xabcf012); */
    /* ft_printf("percent: %%\n"); */

	ft_printf("precision        |%.9d|\n", 43);
	ft_printf("string precision |%.9s|\n", "jesuisbonjourbonjour");
	ft_printf("min width        |%9d|\n", 43);
	ft_printf("zero padding     |%09d|\n", 43);
	ft_printf("left adjusted    |%-9d|\n", 43);
	ft_printf("string padding   |%9s|\n", "bon");

	/* ft_printf("width wildcard           |%*d|\n", 5, 43); */
	/* ft_printf("precision wildcard       |%.*d|\n", 5, 43); */
	/* ft_printf("precision/width wildcard |%*.*d|\n", 5, 3, 43); */
	/* ft_printf("left adjusted            |%*d|\n", -5, 43); */
    /*  */
	/* ft_printf("overwrite |%*3d|\n", 5, 43); */
	/* ft_printf("overwrite |%*-1d|\n", 0, 43); */
    return 0;
}

#endif
