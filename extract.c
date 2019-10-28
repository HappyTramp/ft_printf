#include <stdlib.h>
#include "header.h"

char	*extract_standalone_flags(t_pformat *pformat, char *fmt)
{
	int		i;

	i = 0;
	while (IS_STANDALONE_FLAG(fmt[i]))
	{
		if (!pformat->zero_padding)
			pformat->zero_padding = fmt[i] == '0';
		if (!pformat->left_adjusted)
			pformat->left_adjusted = fmt[i] == '-';
		i++;
	}
 	return (fmt + i);
}

char	*extract_min_width(t_pformat *pformat, char *fmt)
{
	int		i;
	int		tmp;

	i = 0;
	if (*fmt == '*')
	{
		pformat->min_width.wildcard = TRUE;
		i++;
	}
	else
	{
		if (ft_isdigit(fmt[i]))
		{
			tmp = ft_atoi(&fmt[i]);
			while (ft_isdigit(fmt[i]))
				i++;
			pformat->min_width.value = tmp;
			pformat->min_width.wildcard = FALSE;
		}
	}
	return (fmt + i);
}

char	*extract_precision(t_pformat *pformat, char *fmt)
{
	int		i;
	int		tmp;

	if (*fmt != '.')
		return (fmt);
	i = 1;
	if (fmt[i] == '*')
	{
		pformat->precision.wildcard = TRUE;
		i++;
	}
	else if (!ft_isdigit(fmt[i]))
		pformat->precision.value = 0;
	tmp = ft_atoi(&fmt[i]);
	while (ft_isdigit(fmt[i]))
		i++;
	pformat->precision.value = tmp;
	return (fmt + i);
}
