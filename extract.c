#include <stdlib.h>
#include "header.h"

char	*extract_ap_index(t_pformat *pformat, char *fmt)
{
	int		i;
	int		tmp;
	char	*fmt_dup;

	if (!ft_isdigit(*fmt) || *fmt == '0')
		return (fmt);
	tmp = ft_atoi(fmt);
	i = 0;
	while (ft_isdigit(fmt[i]))
		i++;
	if (fmt[i] == '$')
	{
		pformat->ap_index = tmp;
		fmt_dup = ft_strdup(&fmt[++i]);
		free(fmt);
		return (fmt_dup);
	}
	return (fmt);
}

char	*extract_standalone_flags(t_pformat *pformat, char *fmt)
{
	int		i;
	char	*fmt_dup;

	i = 0;
	while (IS_STANDALONE_FLAG(fmt[i]))
	{
		if (!pformat->zero_padding)
			pformat->zero_padding = fmt[i] == '0';
		if (!pformat->left_adjusted)
			pformat->left_adjusted = fmt[i] == '-';
		i++;
	}
	fmt_dup = ft_strdup(&fmt[i]);
	free(fmt);
 	return (fmt_dup);
}

char	*extract_min_width(t_pformat *pformat, char *fmt)
{
	int		i;
	int		tmp;
	char	*fmt_dup;


	i = 0;
	/* if (*fmt == '*') */
	/* { */
	/* 	pformat->min_width.wildcard.exist = TRUE; */
	/* 	i++; */
	/* } */
	if (ft_isdigit(fmt[i]))
	{
		tmp = ft_atoi(&fmt[i]);
		while (ft_isdigit(fmt[i]))
			i++;
		/* printf("%d\n", tmp); */
		/* if (fmt[i] == '$') */
		/* 	pformat->min_width.wildcard.ap_index = tmp; */
		/* else */
		/* { */
			pformat->min_width.hardcoded = tmp;
			pformat->min_width.wildcard.exist = FALSE;
		/* } */
	}
	fmt_dup = ft_strdup(&fmt[i]);
	free(fmt);
	return (fmt_dup);
}

char	*extract_precision(t_pformat *pformat, char *fmt)
{
	int		i;
	int		tmp;
	char	*fmt_dup;

	if (*fmt != '.')
		return (fmt);
	i = 1;
	/* if (fmt[i] == '*') */
	/* { */
	/* 	pformat->precision.wildcard.exist = TRUE; */
	/* 	i++; */
	/* } */
	/* else if (!ft_isdigit(fmt[i])) */
	/* 	pformat->precision.hardcoded = 0; */
	tmp = ft_atoi(&fmt[i]);
	while (ft_isdigit(fmt[i]))
		i++;
	/* if (pformat->precision.wildcard.exist && fmt[i] == '$') */
	/* 	pformat->precision.wildcard.ap_index = tmp; */
	/* else */
		pformat->precision.hardcoded = tmp;
	fmt_dup = ft_strdup(&fmt[i]);
	free(fmt);
	return (fmt);
}
