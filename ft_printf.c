#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
	t_flist	*format_list;
	char	*str;
    int		print_len;
    int		i;

	if ((format_list = parse(format)) == NULL)
		return (-1);
    va_start(ap, format);
    print_len = 0;
	i = -1;
    while (format[++i])
    {
        if (format[i] == '%')
        {
			if ((str = convert_to_str(format_list->content, ap)) == NULL)
			{
				list_destroy(&format_list);
				return (-1);
			}
			ft_putstr(str);
			print_len += ft_strlen(str);
			free(str);
			i += format_list->content->len;
			list_pop_front(&format_list);
        }
        else
            write(STDOUT_FILENO, format + i, 1);
    }
    va_end(ap);
    return (print_len + i);
}
