/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:56:47 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/15 10:42:15 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	minus_flag(unsigned int hex, char *p, t_flags *flags)
{
	if (flags->alternative_form)
		ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(hex, "0123456789abcdef", 1);
	ft_putstr_fd(p, 1);
}

static void	zero_flag(unsigned int hex, char *p, int wdth, t_flags *flags)
{
	ft_memset(p, '0', wdth);
	ft_putstr_fd(p, 1);
	if (flags->alternative_form)
		ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(hex, "0123456789abcdef", 1);
}

static void	nbr_flags(unsigned int hex, int wdth, t_flags *flags)
{
	char	*ptr;

	ptr = is_width_flag(wdth);
	if (flags->minus_flag && !flags->zero_flag)
		minus_flag(hex, ptr, flags);
	else if (!flags->minus_flag && flags->zero_flag)
		zero_flag(hex, ptr, wdth, flags);
	else if (!flags->minus_flag && !flags->zero_flag)
	{
		ft_putstr_fd(ptr, 1);
		if (flags->alternative_form)
			ft_putstr_fd("0X", 1);
		ft_putnbr_base_fd(hex, "0123456789abcdef", 1);
	}
	free (ptr);
}

static void	hex_nbr_precision(t_flags *flags)
{
	if (flags->precision_flag)
	{
		flags->zero_flag = 1;
		flags->width_flag = flags->precision_flag;
	}
}

int	hex_formatx(unsigned int hex, t_flags *flags)
{
	int		len;
	int		width;

	hex_nbr_precision(flags);
	len = nbr_base_len("0123456789abcdef", hex);
	if (flags->alternative_form)
	{
		if (hex == 0)
			flags->alternative_form = 0;
		else
			len += 2;
	}
	width = flags->width_flag - len;
	if (width > 0)
	{
		nbr_flags(hex, width, flags);
		len += width;
	}
	else
	{
		if (flags->alternative_form)
			ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(hex, "0123456789abcdef", 1);
	}
	return (len);
}
