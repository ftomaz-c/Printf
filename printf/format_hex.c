/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:56:47 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/14 17:35:22 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	nbr_minus_zero_flags(unsigned int hex, char *p, int wdth, t_flag_data *flags)
{
	if (flags->minus_flag && !flags->zero_flag)
	{
		ft_putnbr_base_fd(hex, "0123456789abcdef", 1);
		ft_putstr_fd(p, 1);
	}
	else if (!flags->minus_flag && flags->zero_flag)
	{
		ft_memset(p, '0', wdth);
		ft_putstr_fd(p, 1);
		ft_putnbr_base_fd(hex, "0123456789abcdef", 1);
	}
	else if (!flags->minus_flag && !flags->zero_flag)
	{
		ft_putstr_fd(p, 1);
		ft_putnbr_base_fd(hex, "0123456789abcdef", 1);
	}
}

static void	nbr_zero_flag(char *new_ptr, char *p, int wdth, t_flag_data *flags)
{
	if (!flags->zero_flag && wdth > 0)
	{
		new_ptr = is_width_flag(wdth);
		new_ptr[ft_strlen(new_ptr) - 1] = '+';
		ft_strlcpy(p, new_ptr, wdth + 1);
	}
	else
	{
		ft_putchar_fd('+', 1);
		new_ptr = is_width_flag(wdth - 1);
		ft_strlcpy(p, new_ptr, wdth + 1);
	}
	free(new_ptr);
}

static void	nbr_plus_space_flags(unsigned int hex, char *p, int wdth, t_flag_data *flags)
{
	char	*new_ptr;

	new_ptr = NULL;
	if (flags->plus_flag && wdth && hex > 0)
	{
		if (wdth > 0)
		{
			nbr_zero_flag(new_ptr, p, wdth, flags);
		}
		else if (wdth < 0)
			ft_putchar_fd('+', 1);
	}
	if (flags->space_flag && wdth && !flags->plus_flag)
	{
		if (wdth > 0)
		{
			ft_putchar_fd(' ', 1);
			new_ptr = is_width_flag(wdth - 1);
			ft_strlcpy(p, new_ptr, wdth + 1);
			free(new_ptr);
		}
		else if (wdth < 0)
			ft_putchar_fd(' ', 1);
	}
}

static void	hex_nbr_precision(t_flag_data *flags)
{
	if (flags->precision_flag)
	{
		flags->zero_flag = 1;
		flags->width_flag = flags->precision_flag;
	}
}

int	hex_formatx(unsigned int hex, t_flag_data *flags)
{
	char	*ptr;
	int		len;
	int		width;

	hex_nbr_precision(flags);
	len = nbr_base_len("0123456789abcdef", hex);
	width = flags->width_flag - len;
	if (width > 0)
		ptr = is_width_flag(width);
	if ((flags->plus_flag || flags->space_flag) && (width - 1 > 0 || width < 0))
	{
		nbr_plus_space_flags(hex, ptr, width, flags);
		width--;
		len++;
	}
	if (width > 0)
	{
		nbr_minus_zero_flags(hex, ptr, width, flags);
		len += width;
		free(ptr);
	}
	else
		ft_putnbr_base_fd(hex, "0123456789abcdef", 1);
	return (len);
}
