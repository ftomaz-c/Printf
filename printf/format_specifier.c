/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:21:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/10 22:35:46 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_placeholder(const char *format)
{
	if (*format == 'c' || *format == 's' || *format == 'p' || *format == 'd'
		|| *format == 'i' || *format == 'u' || *format == 'x' || *format == 'X')
		return (1);
	return (0);
}

/*int		unsigned_format(int u, t_flag_data *flags)
{}

int		hex_format(char *hex, t_flag_data *flags)
{} */

int	format_spec(const char *format, va_list args, t_flag_data *flags)
{
	int				len;
	char			c;
	char			*s;
	void			*ptr;
	int				nbr;
/*	unsigned int	u;
	char			*hex; */
	char			placeholder = *format;
	len = 0;
	printf("---- placeholder: %%%c ----\n", placeholder);
	if (*format == 'c' )
	{
		c = va_arg(args, int);
		len = char_format(c, flags);
	}
	if (*format == 's')
	{
		s = va_arg(args, char *);
		len = str_format(s, flags);
	}
	if (*format == 'p')
	{
		ptr = va_arg(args, void *);
		len = ptr_format(ptr, flags);
	}
	if (*format == 'd' || *format == 'i')
	{
		nbr = va_arg(args, int);
		len = nbr_format(nbr, flags);
	}
/*	if (*format == 'u')
	{
		u = va_arg(args, unsigned int);
		len = unsigned_format(u, flags);
	}
	if (*format == 'x' || *format == 'X')
	{
		hex = va_arg(args, char *);
		len = hex_format(hex, flags);
	} */
	va_end(args);
	return (len);
}
