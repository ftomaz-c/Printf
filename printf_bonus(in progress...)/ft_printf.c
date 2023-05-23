/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:49:19 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/16 20:13:39 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Iterate through the input until a % sign appears. Write everything
encountered before that point.
2. Once a % sign is found, check if there are any flags present.
3. If a flag is found, handle it accordingly by performing the required
action or modification.
4. Check if there are subsequent flags that may cancel or modify the effect
of the previous flag. Adjust the behavior based on these flags if necessary.
5. For specific flags (e.g., -), check if there are additional parameters
(such as a number) following the flag. Use these parameters to determine the
behavior of the flag.
6. Once all flags have been processed, identify and handle the placeholder.
7.Continue iterating through the input to check if there are any more
occurrences of % signs with flags and placeholders. Repeat steps 2-6 as
necessary.
*/

#include "ft_printf.h"

static char	is_placeholder(const char *format)
{
	if (*format == 'c' || *format == 's' || *format == 'p' || *format == 'd'
		|| *format == 'i' || *format == 'u' || *format == 'x' || *format == 'X')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_flags	*flags;
	int			len;
	va_list		args;

	len = 0;
	if (!format)
		return (len);
	va_start (args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar_fd('%', 1);
			len++;
			format++;
		}
		else if (*format == '%' && *(format + 1) != '%')
		{
			if (is_placeholder(format))
				len += format_spec(format, args, flags);
			if (!is_placeholder(format))
			{
				flags = flag_check(format);
				while (*format && !is_placeholder(format))
					format++;
				len += format_spec(format, args, flags);
				free (flags);
			}
		}
		else if (!(*format == '%'))
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}

/* printf("\n\n> width flag\t\t: %d\n", flags->width_flag);
				printf("> minus flag\t\t: %d\n", flags->minus_flag);
				printf("> precision flag\t: %d\n", flags->precision_flag);
				printf("> zero flag\t\t: %d\n", flags->zero_flag);
				printf("> alternative_form flag\t: %d\n", flags->alternative_form);
				printf("> space flag\t\t: %d\n", flags->space_flag);
				printf("> plus flag\t\t: %d\n\n", flags->plus_flag); */
