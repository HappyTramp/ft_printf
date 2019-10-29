/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:06:46 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/29 05:01:00 by cacharle         ###   ########.fr       */
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

# define IS_STANDALONE_FLAG(c) (c == '0' || c == '-')

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

# define FLAG_LEFT_ADJUSTED       0b00000001
# define FLAG_ZERO_PADDING        0b00000010
# define FLAG_MIN_WIDTH_WILDCARD  0b00000100
# define FLAG_PRECISION_WILDCARD  0b00001000
# define FLAG_MIN_WIDTH_OVERWRITE 0b00010000

#include <stdio.h>

typedef char			t_conversion;
typedef int				t_bool;
typedef unsigned char	t_flags;

typedef struct
{
	int				precision;
	int				min_width;
	t_flags			flags;
	t_conversion	conversion;
	int				len;
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

t_flist				*parse(char *format);
t_pformat			*parse_reduced(char *fmt);

/*
** printer.c
*/

char	*convert(t_pformat *pformat, va_list ap);
char	*convert_type(t_conversion conversion, va_list ap);
char	*handle_padding(t_pformat *pformat, char *str);
char	*handle_precision(t_pformat *pformat, char *str);
char				*add_address_prefix(char *addr);

/*
** utils.c
*/

int					strrchr_index(const char *s, char c);

/*
** extract.c
*/

char				*extract_standalone_flags(t_pformat *pformat, char *fmt);
char				*extract_min_width(t_pformat *pformat, char *fmt);
char				*extract_precision(t_pformat *pformat, char *fmt);

/*
** list.c
*/

t_flist				*list_new(t_pformat *content);
void				*list_destroy(t_flist **lst);
void				list_push_front(t_flist **lst, t_flist *new);
void				list_pop_front(t_flist **lst);
t_flist				*list_reverse(t_flist *lst);

#endif
