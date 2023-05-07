/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:52:54 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/07 17:05:27 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

Flag flag_check(const char *format)
{
    if(!format)
		return (0);

	while(*format)
	{
		if(*format == '%')
		{
			format++;
			while(*format == '-' || *format == '0' || *format == '.'
				||*format == '#' || *format == ' ' || *format == '+')
			{
				if(*format == '-')
				{
					return (1);
				}
				else if(*format == '0')
				{
					return (2);
				}
				else if(*format == '.')
				{
					return (3);
				}
				else if(*format == '#')
				{
					return (4);
				}
				else if(*format == ' ')
				{
					return (5);
				}
				else if(*format == '+')
				{
					return (6);
				}
				format++;
			}
		}
		format++;
	}
	return (0);
}
