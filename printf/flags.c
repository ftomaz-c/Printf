/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:22:30 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/08 19:05:14 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		width_flag (const char *format)
{
	int		len;

	if (*format < '1' || *format > '9')
		return (-1);
	len = 0;
	while (*format >= '0' && *format <= '9')
	{
		len = len * 10 + (*format - '0');
		format++;
	}
	return(len);
}

char	minus_flag (const char *format)
{
	char	c;

	c = ' ';
	return(c);
}

char	zero_flag (const char *format)
{
	char	c;

	c = '0';
	return(c);
}

int		precision_flag(const char *format)
{
	int		len;

	len = 0;
	while (*format >= '0' && *format <= '9')
	{
		len = len * 10 + (*format - '0');
		format++;
	}
	if (len == 0)
		return (-1);
	return (len);
}

char	*alternative_form(const char *format)
{
	char	*ptr;

	if (*format == 'x')
		ptr = ft_strdup("0x");
	else if (*format == 'X')
		ptr = ft_strdup("0X");
	else
		return (NULL);
	if (!ptr)
	{
		free (ptr);
		return (NULL);
	}
	return (ptr);
}
