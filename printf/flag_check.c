/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:52:54 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/09 18:34:42 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	'-' (minus): Left-aligns the output.
	'0' (zero): Pads the output with zeros on the left.
	'.' (period): Specifies the precision (number of decimal places).
	'#' (hash): Enables alternative representations for specific format
	specifiers.
	' ' (space): Adds a space before positive numbers.
	'+' (plus): Adds a sign symbol ('+' or '-') for signed values.

	The '-' flag cancels the '0' flag.
	The '+' flag cancels the ' ' (space) flag. */

#include "ft_printf.h"

static void	flag_check1(const char *format, flag_data *flags)
{
	if(*format == '-')
	{
		flags->minus_flag = 1;
		format++;
		if (*format >= '0' && *format <= '9')
		{
			flags->width_flag = width_flag(format);
			while (*format >= '0' && *format <= '9')
				format++;
		}
	}
	if (*format == '0')
	{
		flags->zero_flag = 1;
		format++;
	}
	if(*format == '.')
	{
		flags->precision_flag = precision_flag(format);
		format++;
		while (*format > '0' && *format < '9' && *format == '.')
			format++;
	}
}

static void	flag_check2(const char *format, flag_data *flags)
{
	if (*format == '#')
	{
		flags->alternative_form = alternative_form(format);
	}
	if(*format == ' ')
	{
		flags->space = ' ';
	}
	if(*format == '+')
	{
		flags->plus = '+';
	}
}

flag_data	*flag_check(const char *format)
{
	flag_data	*flags;

	flags = ft_calloc(1, sizeof(flag_data));
	if (!flags || !format)
		return (NULL);
	if(*format == '%')
	{
		format++;
		if (*format >= '0' && *format <= '9')
		{
			flags->width_flag = width_flag(format);
			while (*format >= '0' && *format <= '9')
				format++;
		}
		while(*format == '-' || *format == '0' || *format == '.'
			||*format == '#' || *format == ' ' || *format == '+')
		{
			if(*format == '-' || *format == '0' || *format == '.')
				flag_check1(format, flags);
			else if(*format == '#' || *format == ' ' || *format == '+')
				flag_check2(format, flags);
			format++;
		}
	}
	return (flags);
}
