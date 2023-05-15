/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:15:00 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/15 12:35:33 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	nbr_minus_zero_flags(int i, char *p, int wdth, t_flags *flags)
{
	if (i < 0 && flags->zero_flag)
	{
		ft_putchar_fd('-', 1);
		i *= -1;
	}
	if (flags->minus_flag && !flags->zero_flag)
	{
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(p, 1);
	}
	else if (!flags->minus_flag && flags->zero_flag)
	{
		ft_memset(p, '0', wdth);
		ft_putstr_fd(p, 1);
		ft_putnbr_fd(i, 1);
	}
	else if (!flags->minus_flag && !flags->zero_flag)
	{
		ft_putstr_fd(p, 1);
		ft_putnbr_fd(i, 1);
	}
}

static void	nbr_zero_flag(char *new_ptr, char *p, int wdth, t_flags *flags)
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

static void	nbr_plus_space_flags(int i, char *p, int wdth, t_flags *flags)
{
	char	*new_ptr;

	new_ptr = NULL;
	if (flags->plus_flag && wdth && i >= 0)
	{
		if (wdth > 0)
			nbr_zero_flag(new_ptr, p, wdth, flags);
		else if (wdth < 0)
			ft_putchar_fd('+', 1);
	}
	if (flags->space_flag && wdth && i >= 0 && !flags->plus_flag)
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

static void	nbr_precision(int nbr, t_flags *flags)
{
	if (flags->precision_flag)
	{
		flags->zero_flag = 1;
		if (nbr >= 0)
			flags->width_flag = flags->precision_flag;
		if (nbr < 0)
			flags->width_flag = flags->precision_flag + 1;
	}
}

int	nbr_format(long long nbr, t_flags *flags)
{
	char	*ptr;
	int		len;
	int		width;

	nbr_precision(nbr, flags);
	len = nbr_len(nbr);
	width = flags->width_flag - len;
	if (width > 0)
		ptr = is_width_flag(width);
	if ((flags->plus_flag || flags->space_flag) && (width - 1 > 0 || width < 0)
		&& nbr >= 0)
	{
		nbr_plus_space_flags(nbr, ptr, width, flags);
		width--;
		len++;
	}
	if (width > 0)
	{
		nbr_minus_zero_flags(nbr, ptr, width, flags);
		len += width;
		free(ptr);
	}
	else
		ft_putnbr_fd(nbr, 1);
	return (len);
}
