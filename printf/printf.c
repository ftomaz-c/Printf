/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:49:19 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/04 18:30:29 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Get placeholder %cspdiuxX - const char*;

2. Verify flags '-', '0', '.', '#', ' ' and '+';

3. Verify placeholder %cspdiuxX;

4. Redirect pointer to the specified placeholder;

5. print the output in the terminal using write ();
*/

#include <stdarg.h>

int flags_check(const char *format)
{
    if(!format)
		return 0;
	
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			while(format == '-' || format == '0' || format == '.' 
				||format == '#' ||format == ' ' ||format == '+')
			{
				if(*format == '-')
				{}
				else if(*format == '0')
				{}
				else if(format == '.')
				{}
				else if(format == '#')
				{}
				else if(format == ' ')
				{}
				else if(format == '+')
				{}
				format++;
			}
		}
		format++;	
	}
}

int ft_printf(const char *format, ...)
{
	int	flags;

	if(!format)
		return 0;
    flags = flags_check(format);
}