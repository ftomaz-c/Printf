/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:49:19 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/09 19:17:47 by ftomaz-c         ###   ########.fr       */
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

int	ft_printf(const char *format, ...)
{
	flag_data	*flags;
	int			len;
	va_list		args;

	len = 0;
	if (!format)
		return (len);
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
		{
			flags = flag_check(format);
			printf("> minus flag\t: %d\n", flags->minus_flag);
			printf("> width flag\t: %d\n", flags->width_flag);
			printf("> precision flag: %d\n\n", flags->precision_flag);
			while (*format && !is_placeholder(format))
				format++;
			if (*format)
				len += format_specifier(format, args, flags);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}

/* int main()
{
	int		len;
	char	*p;

	p = "string";
	ft_printf("\nTesting ft_printf:\n\n");
	len = ft_printf("%16p|\n ", p);
	printf ("Length: %d\n", len);
	printf ("\n--------------------------\n");
	printf("\nTesting printf:\n\n");
	len = printf("%16p|\n ", p);
	printf("Length: %d\n\n", len);

	return 0;
} */
