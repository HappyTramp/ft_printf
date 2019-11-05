/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:06:46 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/05 23:58:48 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define SPECIFIERS_STR "ncspdiuxX%"
# define FLAGS_STR      "#0- +'"

# define IS_STANDALONE_FLAG(c) (ft_strchr(FLAGS_STR, c) != NULL)

# define FLAG_MINUS               (1 << 0)
# define FLAG_ZERO                (1 << 1)
# define FLAG_SIGNED              (1 << 2)
# define FLAG_SPACE               (1 << 3)
# define FLAG_ALTERNATE           (1 << 4)
# define FLAG_SHORT               (1 << 5)
# define FLAG_SHORT_SHORT         (1 << 6)
# define FLAG_LONG                (1 << 7)
# define FLAG_LONG_LONG           (1 << 8)
# define FLAG_WIDTH_WILDCARD      (1 << 9)
# define FLAG_PRECISION_WILDCARD  (1 << 10)
# define FLAG_WIDTH_OVERWRITE     (1 << 11)

# define ITOA_HEX_LOW(x) (ft_itoa_unsigned_base(x, "0123456789abcdef"))
# define ITOA_HEX_UP(x)  (ft_itoa_unsigned_base(x, "0123456789ABCDEF"))
# define ITOA_DEC(x)     (ft_itoa_base(x, "0123456789"))

typedef int		t_bool;
typedef short	t_flags;

typedef struct
{
	int				precision;
	int				width;
	t_flags			flags;
	char			specifier;
	int				fmt_len;
	int				size;
	long long int	*written;
}					t_pformat;

typedef struct		s_flist
{
	struct s_flist	*next;
	t_pformat		*content;
}					t_flist;

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

char				*convert(t_pformat *pformat, va_list ap);
char				*convert_specifier(va_list ap, t_pformat *pformat);
char				*handle_width(t_pformat *pformat, char *str);
char				*handle_precision(t_pformat *pformat, char *str);

/*
** utils.c
*/

char				*ft_itoa_base(long long int n, char *base);
char				*ft_itoa_unsigned_base(long long unsigned int n,
											char *base);
char				*ft_strtoupper(char *str);

/*
** extract.c
*/

char				*extract_flags(t_pformat *pformat, char *fmt);
char				*extract_width(t_pformat *pformat, char *fmt);
char				*extract_precision(t_pformat *pformat, char *fmt);
char				*extract_length_modifier(t_pformat *pformat, char *fmt);

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

char				*convert_char(va_list ap, t_pformat *pformat);
char				*convert_str(va_list ap, t_pformat *pformat);
char				*convert_ptr(va_list ap, t_pformat *pformat);
char				*convert_int(va_list ap, t_pformat *pformat);
char				*convert_uint(va_list ap, t_pformat *pformat);
char				*convert_hex(va_list ap, t_pformat *pformat);
char				*convert_percent(va_list ap, t_pformat *pformat);
char				*convert_written(va_list ap, t_pformat *pformat);
char				*convert_none(va_list ap, t_pformat *pformat);

/*
** length_modifier.c
*/

long long unsigned int	length_modifier_unsigned_int(
							va_list ap, t_pformat *pformat);
long long int			length_modifier_int(va_list ap, t_pformat *pformat);

#endif
