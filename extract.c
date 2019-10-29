/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:10:36 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/29 18:17:38 by cacharle         ###   ########.fr       */
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
		fmt++;
	}
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
