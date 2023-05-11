/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:11:45 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/11 15:54:34 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	unbr_minus_zero_flags(int i, char *p, int wdth, t_flag_data *flags)
{
	if (i < 0 && flags->zero_flag)
	{
		ft_putchar_fd('-', 1);
		i *= -1;
	}
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

static void	unbr_zero_flag(char *new_ptr, char *p, int wdth, t_flag_data *flags)
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

static void	unbr_plus_space_flags(int i, char *p, int wdth, t_flag_data *flags)
{
	char	*new_ptr;

	new_ptr = NULL;
	if (flags->plus_flag && wdth && i > 0)
	{
		if (wdth > 0)
		{
			unbr_zero_flag(new_ptr, p, wdth, flags);
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

static int	unbr_base_len(char *base, long long nbr)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
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

int	unsigned_format(unsigned int i, t_flag_data *flags)
{
	char	*ptr;
	int		len;
	int		width;

	len = unbr_base_len("0123456789", i);
	width = flags->width_flag - len;
	if (width > 0)
		ptr = is_width_flag(width);
	if ((flags->plus_flag || flags->space_flag) && (width - 1 > 0 || width < 0))
	{
		unbr_plus_space_flags(i, ptr, width, flags);
		width--;
		len++;
	}
	if (width > 0)
	{
		unbr_minus_zero_flags(i, ptr, width, flags);
		len += width;
		free(ptr);
	}
	else
		ft_putunbr_fd(i, 1);
	return (len);
}
