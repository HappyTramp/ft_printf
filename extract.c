/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:10:36 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/30 19:42:16 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

char	*extract_standalone_flags(t_pformat *pformat, char *fmt)
{
	if (*fmt == 0)
		return (fmt);
	while (IS_STANDALONE_FLAG(*fmt))
	{
		if (*fmt == '0')
			pformat->flags |= FLAG_ZERO_PADDING;
		if (*fmt == '-')
			pformat->flags |= FLAG_LEFT_ADJUSTED;
		if (*fmt == '+')
			pformat->flags |= FLAG_SIGNED;
		if (*fmt == ' ')
			pformat->flags |= FLAG_SPACE;
		if (*fmt == '#')
			pformat->flags |= FLAG_ALTERNATE;
		if (*fmt == '\'')
			;
		fmt++;
	}
	if (pformat->flags & FLAG_SIGNED)
		pformat->flags &= ~FLAG_SPACE;
	return (fmt);
}

char	*extract_min_width(t_pformat *pformat, char *fmt)
{
	if (*fmt == 0)
		return (fmt);
	if (*fmt == '*')
	{
		pformat->flags |= FLAG_MIN_WIDTH_WILDCARD;
		fmt++;
	}
	if (!ft_isdigit(*fmt))
		return (fmt);
	pformat->min_width = ft_atoi(fmt);
	while (*fmt && ft_isdigit(*fmt))
		fmt++;
	if (pformat->flags & FLAG_MIN_WIDTH_WILDCARD)
		pformat->flags |= FLAG_MIN_WIDTH_OVERWRITE;
	return (fmt);
}

char	*extract_precision(t_pformat *pformat, char *fmt)
{
	if (*fmt == 0 || *fmt != '.')
		return (fmt);
	pformat->flags &= ~FLAG_ZERO_PADDING;
	fmt++;
	if (*fmt == '*')
	{
		pformat->flags |= FLAG_PRECISION_WILDCARD;
		fmt++;
	}
	pformat->precision = ft_atoi(fmt);
	while (*fmt && ft_isdigit(*fmt))
		fmt++;
	return (fmt);
}

char	*extract_length_modifier(t_pformat *pformat, char *fmt)
{
	if (fmt[0] && fmt[0] == 'l')
	{
		if (fmt[1] && fmt[1] == 'l')
		{
			pformat->flags |= FLAG_LONG_LONG;
			return (fmt + 2);
		}
		pformat->flags |= FLAG_LONG;
		return (fmt + 1);
	}
	if (fmt[0] && fmt[0] == 'h')
	{
		if (fmt[1] && fmt[1] == 'h')
		{
			pformat->flags |= FLAG_SHORT_SHORT;
			return (fmt + 2);
		}
		pformat->flags |= FLAG_SHORT;
		return (fmt + 1);
	}
	return (fmt);
}
