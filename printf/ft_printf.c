/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:49:19 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/11 01:42:58 by ftomaz-c         ###   ########.fr       */
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
	t_flag_data	*flags;
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
			printf("\n\n> width flag\t\t: %d\n", flags->width_flag);
			printf("> minus flag\t\t: %d\n", flags->minus_flag);
			printf("> precision flag\t: %d\n", flags->precision_flag);
			printf("> zero flag\t\t: %d\n", flags->zero_flag);
			printf("> alternative_form flag\t: %d\n", flags->alternative_form);
			printf("> space flag\t\t: %d\n", flags->space_flag);
			printf("> plus flag\t\t: %d\n\n", flags->plus_flag);
			while (*format && !is_placeholder(format))
				format++;
			if (*format)
				len += format_spec(format, args, flags);
			free (flags);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	printf ("\n-------------------------\n\n");
	return (len);
}

int main()
{
    int number = 42;

    ft_printf("Number: %d|\n\n", number);
    ft_printf("Number with width: %5d|\n\n", number);
    ft_printf("Number with zero padding: %05d|\n\n", number);
    ft_printf("Number with left alignment: %-5d|\n\n", number);
    ft_printf("Number with plus flag: %+d|\n\n", number);
    ft_printf("Number with space flag: % d|\n\n", number);
    ft_printf("Number with precision: %.2d|\n\n", number);

    int negative_number = -123;

    ft_printf("Negative number: %d|\n\n", negative_number);
    ft_printf("Negative number with width: %8d|\n\n", negative_number);
    ft_printf("Negative number with zero padding: %010d|\n\n", negative_number);
    ft_printf("Negative number with left alignment: %-8d|\n\n", negative_number);
    ft_printf("Negative number with plus flag: %+d|\n\n", negative_number);
    ft_printf("Negative number with space flag: % d|\n\n", negative_number);
    ft_printf("Negative number with precision: %.3d|\n\n", negative_number);

    int zero = 0;

    ft_printf("Zero: %d|\n\n", zero);
    ft_printf("Zero with width: %5d|\n\n", zero);
    ft_printf("Zero with zero padding: %08d|\n\n", zero);
    ft_printf("Zero with left alignment: %-5d|\n\n", zero);
    ft_printf("Zero with plus flag: %+d|\n\n", zero);
    ft_printf("Zero with space flag: % d|\n\n", zero);
    ft_printf("Zero with precision: %.1d|\n\n", zero);

/* 	int	len;
	int	i;

	i = 0;
	ft_printf("\n\n\n\nTesting ft_printf:\n\n");
	len = ft_printf("% i|\n", i);
	printf ("Length: %d\n", len);
	printf ("\n-------------------------\n");
	printf("\nTesting printf:\n\n");
	len = printf("% i|\n", i);
	printf("Length: %d\n\n", len);
*/
	return (0);
}
