/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:06:46 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/30 04:14:35 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0

# define HEX_SYMBOLS "0123456789abcdef"
# define HEX_MAJ_SYMBOLS "0123456789ABCDEF"

# define IN_STR(str, c) (ft_strchr(str, c) != NULL)
# define IS_STANDALONE_FLAG(c) (IN_STR("0-+ #", c))

# define CONVERSIONS_STR "cspdiuxX%"

# define CONVERSION_CHAR 'c'
# define CONVERSION_STR 's'
# define CONVERSION_PTR 'p'
# define CONVERSION_DECIMAL 'd'
# define CONVERSION_INT 'i'
# define CONVERSION_UINT 'u'
# define CONVERSION_HEX_LOWER 'x'
# define CONVERSION_HEX_UPPER 'X'
# define CONVERSION_PERCENT '%'

# define FLAG_LEFT_ADJUSTED       (1 << 0)
# define FLAG_ZERO_PADDING        (1 << 1)
# define FLAG_MIN_WIDTH_WILDCARD  (1 << 2)
# define FLAG_PRECISION_WILDCARD  (1 << 3)
# define FLAG_MIN_WIDTH_OVERWRITE (1 << 4)
# define FLAG_SIGNED              (1 << 5)
# define FLAG_SPACE               (1 << 6)
# define FLAG_ALTERNATE           (1 << 7)
# define FLAG_SHORT_SHORT         (1 << 8)
# define FLAG_SHORT               (1 << 9)
# define FLAG_LONG                (1 << 10)
# define FLAG_LONG_LONG           (1 << 11)

#define ITOA_HEX_LOW(x) (ft_itoa_unsigned_base(x, "0123456789abcdef"))
#define ITOA_HEX_UP(x) (ft_itoa_unsigned_base(x, "0123456789ABCDEF"))
#define ITOA_DEC(x) (ft_itoa_base(x, "0123456789"))

#include <stdio.h>

typedef int				t_bool;
typedef short			t_flags;

typedef struct
{
	int				precision;
	int				min_width;
	t_flags			flags;
	char			type;
	int				len;
}					t_pformat;

typedef struct		s_flist
{
	struct s_flist	*next;
	t_pformat		*content;
}					t_flist;

typedef struct
{
	char	*(*func)(va_list ap, t_pformat *pformat);
	char	type;
}					t_converter;

/*
** ft_printf.c
*/

int					ft_printf(const char *format, ...);

/*
** parse.c
*/

int					parse(char *format, t_flist **flist);
t_pformat			*parse_reduced(char *fmt);

/*
** printer.c
*/

char	*convert(t_pformat *pformat, va_list ap);
char	*convert_type(va_list ap, t_pformat *pformat);
char	*handle_padding(t_pformat *pformat, char *str);
char	*handle_precision(t_pformat *pformat, char *str);
char	*add_hex_prefix(char *str);

/*
** utils.c
*/

int					strrchr_index(const char *s, char c);
char		*ft_itoa_base(long long int n, char *base);
char	*ft_itoa_unsigned_base(long long unsigned int n, char *base);

/*
** extract.c
*/

char				*extract_standalone_flags(t_pformat *pformat, char *fmt);
char				*extract_min_width(t_pformat *pformat, char *fmt);
char				*extract_precision(t_pformat *pformat, char *fmt);
char	*extract_length_modifier(t_pformat *pformat, char *fmt);

/*
** list.c
*/

t_flist				*list_new(t_pformat *content);
void				*list_destroy(t_flist **lst);
void				list_push_front(t_flist **lst, t_flist *new);
void				list_pop_front(t_flist **lst);
t_flist				*list_reverse(t_flist *lst);


/*
** convert_*.c
*/

char	*convert_char(va_list ap, t_pformat *pformat);
char	*convert_str(va_list ap, t_pformat *pformat);
char	*convert_ptr(va_list ap, t_pformat *pformat);
char	*convert_int(va_list ap, t_pformat *pformat);
char	*convert_uint(va_list ap, t_pformat *pformat);
char	*convert_hex_low(va_list ap, t_pformat *pformat);
char	*convert_hex_up(va_list ap, t_pformat *pformat);
char	*convert_percent(va_list ap, t_pformat *pformat);

#endif
