/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:15:00 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/11 02:29:47 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	nbr_minus_zero_flags(int i, char *p, int wdth, t_flag_data *flags)
{
	if (i < 0 && flags->zero_flag)
	{
		ft_putchar_fd('-', 1);
		i *= -1;
	}
	if (flags->minus_flag && !flags->zero_flag)
	{
		ft_putnbr_base_fd(i, "0123456789", 1);
		ft_putstr_fd(p, 1);
	}
	else if (!flags->minus_flag && flags->zero_flag)
	{
		ft_memset(p, '0', wdth);
		ft_putstr_fd(p, 1);
		ft_putnbr_base_fd(i, "0123456789", 1);
	}
	else if (!flags->minus_flag && !flags->zero_flag)
	{
		ft_putstr_fd(p, 1);
		ft_putnbr_base_fd(i, "0123456789", 1);
	}
}

static void	nbr_plus_space_flags(int i, char *p, int wdth, t_flag_data *flags)
{
	char	*new_ptr;

	if (flags->plus_flag && wdth && i > 0)
	{
		if (wdth > 0)
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

int	nbr_format(int i, t_flag_data *flags)
{
	char	*ptr;
	int		len;
	int		width;

	len = nbr_base_len("0123456789", i);
	printf("\nlen = %d\n", len);
	width = flags->width_flag - len;
	printf("width = %d\n\n", width);
	if (width > 0)
		ptr = is_width_flag(width);
	if ((flags->plus_flag || flags->space_flag) && (width - 1 > 0 || width < 0))
	{
		nbr_plus_space_flags(i, ptr, width, flags);
		width--;
		len++;
	}
	if (width > 0)
	{
		nbr_minus_zero_flags(i, ptr, width, flags);
		len += width;
		free(ptr);
	}
	else
		ft_putnbr_base_fd(i, "0123456789", 1);
	return (len);
}
