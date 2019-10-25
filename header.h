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

typedef char	t_conversion;
typedef int		t_bool;

typedef struct
{
	int			value;
	struct
	{
		t_bool	exist;
		int		ap_index;
	}			wildcard;
}				t_maybe_wildcard;

typedef struct
{
	int						ap_index;
	t_bool					left_adjusted;
	t_bool					zero_padding;
	t_maybe_wildcard		precision;
	t_maybe_wildcard		min_width;
	t_conversion			conversion;
	int						len;
}							t_pformat;

typedef struct				s_pformat_list
{
    struct s_pformat_list	*next;
    t_pformat				*content;
}							t_pformat_list;

/*
** ft_printf.c
*/

int							ft_printf(const char *format, ...);

/*
** parse.c
*/


t_pformat_list				*parse(const char *format);
char						*isolate_conversion(const char *conversion_start);
t_pformat					*parse_reduced(char *fmt);

/*
** printer.c
*/

void						handle_padding(t_pformat *pformat, char *str);
char						*convert_to_str(t_pformat *pformat, va_list ap);
void						handle_precision(t_pformat *pformat, char *str);

/*
** utils.c
*/

int		strrchr_index(const char *s, char c);

/*
** extract.c
*/

// char	*extract_ap_index(t_pformat *pformat, char *fmt);

char						*extract_min_width(t_pformat *pformat, char *fmt);
char						*extract_standalone_flags(t_pformat *pformat, char *fmt);
char						*extract_precision(t_pformat *pformat, char *fmt);

/*
** list.c
*/

t_pformat_list				*list_new(t_pformat *content);
void						*list_destroy(t_pformat_list **lst);
void						list_push_front(t_pformat_list **lst, t_pformat_list *new);
void						list_push_back(t_pformat_list **lst, t_pformat_list *new);
void						list_pop_front(t_pformat_list **lst);

#endif
