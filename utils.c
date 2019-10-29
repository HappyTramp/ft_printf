/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:12:40 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/29 00:12:52 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

#define MIN_INT (1 << 31)
#define MAX_INT (~(1 << 31))

int		strrchr_index(const char *s, char c)
{
	int i;

	i = ft_strlen((char*)s) - 1;
	while (s[i] != c)
	{
		if (i == 0)
			return (-1);
		i--;
	}
	return (i);
}
