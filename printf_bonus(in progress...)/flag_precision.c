/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:24:36 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/10 19:46:53 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision_flag(const char *format)
{
	int		len;

	len = 0;
	format++;
	while (*format >= '0' && *format <= '9')
	{
		len = len * 10 + (*format - '0');
		format++;
	}
	if (len == 0)
		return (-1);
	return (len);
}
