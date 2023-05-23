/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:11:45 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/15 12:54:19 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	nbr_minus_zero_flags(int i, char *p, int wdth, t_flags *flags)
{
	if (flags->minus_flag && !flags->zero_flag)
	{
		ft_putunbr_fd(i, 1);
		ft_putstr_fd(p, 1);
	}
	else if (!flags->minus_flag && flags->zero_flag)
	{
		ft_memset(p, '0', wdth);
		ft_putstr_fd(p, 1);
		ft_putunbr_fd(i, 1);
	}
	else if (!flags->minus_flag && !flags->zero_flag)
	{
		ft_putstr_fd(p, 1);
		ft_putunbr_fd(i, 1);
	}
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunbr_fd(n / 10, fd);
		n = n % 10;
	}
	ft_putchar_fd(n + '0', fd);
}

static void	unbr_precision(t_flags *flags)
{
	if (flags->precision_flag)
	{
		flags->zero_flag = 1;
		flags->width_flag = flags->precision_flag;
	}
}

int	unsigned_format(unsigned int i, t_flags *flags)
{
	char	*ptr;
	int		len;
	int		width;

	unbr_precision(flags);
	len = nbr_len(i);
	width = flags->width_flag - len;
	if (width > 0)
		ptr = is_width_flag(width);
	if (width > 0)
	{
		nbr_minus_zero_flags(i, ptr, width, flags);
		len += width;
		free(ptr);
	}
	else
		ft_putunbr_fd(i, 1);
	return (len);
}
