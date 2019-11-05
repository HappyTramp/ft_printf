/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:22:25 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/05 23:43:57 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*convert_str(va_list ap, t_pformat *pformat)
{
	char *str;

	str = va_arg(ap, char*);
	str = str == NULL ? ft_strdup("(null)") : ft_strdup(str);
	if (pformat->precision != -1 && pformat->precision < (int)ft_strlen(str))
		str[pformat->precision] = '\0';
	str = handle_width(pformat, str);
	return (str);
}
