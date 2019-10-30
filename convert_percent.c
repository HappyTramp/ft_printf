/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:23:27 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/30 23:23:56 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "header.h"

char	*convert_percent(va_list ap, t_pformat *pformat)
{
	char *str;

	(void)ap;
	str = ft_strdup("%");
	str = handle_padding(pformat, str);
	return (str);
}
