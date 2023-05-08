/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:21:08 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/08 22:24:48 by ftomaz-c         ###   ########.fr       */
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

char	*is_width_flag(int len)
{
	char	*ptr;

	ptr = calloc(len + 1, sizeof(char));
	if(!ptr)
		return (NULL);
	ft_memset(ptr, ' ', len);
	return (ptr);
}

static int		char_format(int c, flag_data *flags)
{
	char	*ptr;
	int		len;

	ptr = NULL;
	len = flags->width_flag;
	if (flags->width_flag > 0)
	{
		ptr = is_width_flag(flags->width_flag - 1);
		ft_putstr_fd(ptr, 1);
		ft_putchar_fd(c, 1);
		free(ptr);
	}
	else
	{
		ft_putchar_fd(c, 1);
		len = 1;
	}
	return(len);
}

/* int		str_format(char *s, flag_data *flags)
{}

int		ptr_format(void *ptr, flag_data *flags)
{}

int		unsigned_format(int u, flag_data *flags)
{}

int		hex_format(char *hex, flag_data *flags)
{} */

int		format_specifier(const char *format, va_list args, flag_data *flags)
{
	int				len;
	char			c;
	/* char			*s;
	void			*ptr;
	int				nbr;
	unsigned int	u;
	char			*hex; */

	len = 0;
	if (*format == 'c' )
	{
		c = va_arg(args, int);
		len = char_format(c, flags);
	}
/* 	if (*format == 's')
	{
		s = va_arg(args, char *);
		len = str_format(s, flags);
	}
	if (*format == 'p')
	{
		ptr = va_arg(args, void*);
		len = ptr_format(ptr, flags);
	}
	if (*format == 'd' || *format == 'i')
	{
		nbr = va_arg(args, int);
		len = nbr_format(nbr, flags);
	}
	if (*format == 'u')
	{
		u = va_arg(args, unsigned int);
		len = unsigned_format(u, flags);
	}
	if (*format == 'x' || *format == 'X')
	{
		hex = va_arg(args, char *);
		len = hex_format(hex, flags);
	} */
	return (len);
}
