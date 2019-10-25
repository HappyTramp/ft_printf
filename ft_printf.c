#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

int ft_printf(const char *format, ...)
{
    int print_len;
    /* va_list ap; */
	/* #<{(| va_list ap_start; |)}># */
	/* #<{(| int ap_index; |)}># */
	/* t_list	*format_list; */
	/* char	*str; */
    /*  */
	/* if ((format_list = parse(format)) == NULL) */
	/* 	return (-1); */
	/* #<{(| ap_index = 0; |)}># */
    /* va_start(ap, format); */
    /*  */
	/* #<{(| va_copy(ap_start, ap); |)}># */
    /* print_len = -1; */
    /* while (format[++print_len]) */
    /* { */
    /*     if (format[print_len] == '%') */
        /* { */
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
	/* 		if ((str = convert_to_str(format_list->content, ap)) == NULL) */
	/* 			return (-1); */
	/* 		ft_putstr(str); */
	/* 		free(str); */
    /*  */
	/* 		print_len += format_list->content->len; */
	/* 		list_pop_front(&format_list); */
    /*     } */
    /*     else */
    /*         write(STDOUT_FILENO, format + print_len, 1); */
    /* } */
    /* va_end(ap); */
	(void)format;
	print_len = 0;
    return (print_len);
}
