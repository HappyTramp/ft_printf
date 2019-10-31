/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_written.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:38:28 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/30 23:59:05 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "header.h"

char	*convert_written(va_list ap, t_pformat *pformat)
{
	pformat->written = va_arg(ap, int*);
	return (NULL);
}
