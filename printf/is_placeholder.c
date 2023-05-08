/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:21:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/08 19:05:12 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	is_placeholder(const char *format)
{
	if (*format == 'c' || *format == 's' || *format == 'p' || *format == 'd'
	|| *format == 'i' || *format == 'u' || *format == 'x' || *format == 'X')
		return (1);
	return (0);
}

int	handle_placeholder(const char *format, va_list args, flag_data *flags)
{
	return (0);
}
