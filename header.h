#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>

# define TRUE 1
# define FALSE 0

# define HEX_SYMBOLS "0123456789abcdef"
# define HEX_MAJ_SYMBOLS "0123456789ABCDEF"

# define PUTXNBR(nb) (ft_putxnbr(nb, HEX_SYMBOLS))
# define PUTXMAJNBR(nb) (ft_putxnbr(nb, HEX_MAJ_SYMBOLS))

# define CONVERSIONS_STR "cspdiuxX%"

typedef enum
{
	CONVERSION_CHAR = 0,
	CONVERSION_STR,
	CONVERSION_PTR,
	CONVERSION_DECIMAL,
	CONVERSION_INT,
	CONVERSION_UINT,
	CONVERSION_HEX_LOWER,
	CONVERSION_HEX_UPPER,
	CONVERSION_PERCENT
}	t_conversion;

typedef int	t_bool;

typedef struct
{
	int				ap_index;
	t_bool			left_adjusted;
	t_bool			zero_padding;
	int				precision;
	t_bool			precision_wildcard;
	int				min_field_width;
	t_bool			min_field_width_wildcard;
	t_conversion	conversion;
	int				len;
}	t_pformat;

typedef struct		s_list
{
    struct s_list	*next;
    t_pformat		*data;
}					t_list;

/*
** ft_printf.c
*/

int ft_printf(const char *format, ...);

/*
** parse.c
*/


t_list		*parse(const char *format);
char		*isolate_conversion(const char *conversion_start);
t_pformat	*parse_conversion(char *conversion);
char	*parse_arg_position(char *conversion, t_pformat *pformat);

/*
** printer.c
*/

void	ft_putstr(char *str);
int		nbrlen_radix(int nbr, int radix);
char	*ft_itoa(int n);
char	*ft_strnew(int size);
char	*ft_strdup(char *s);
char	*ft_strcpy(char *dest, const char *src);
void	handle_padding(t_pformat *pformat, char *str);
char	*convert_to_str(t_pformat *pformat, va_list ap);
void	handle_precision(t_pformat *pformat, char *str);

/*
** utils.c
*/

int			ft_atoi(const char *str);
char	*ft_strndup(const char *s1, int n);
char	*ft_strrchr(const char *s, int c);
int		strrchr_index(const char *s, char c);
int		ft_strlen(char *str);
t_bool	ft_isdigit(char c);

/*
** list.c
*/

t_list	*list_new(t_pformat *data);
t_list	*list_destroy(t_list *list);
void	list_push_front(t_list **list, t_list *new_front);
void	list_push_back(t_list **list, t_list *new_back);
void	list_pop_front(t_list **list);

#endif
