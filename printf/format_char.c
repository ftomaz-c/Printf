/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:04:00 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/15 12:51:11 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	width_char(int c, t_flags *flags)
{
	char	*ptr;

	ptr = is_width_flag(flags->width_flag - 1);
	if (flags->minus_flag == 0)
	{
		ft_putstr_fd(ptr, 1);
		ft_putchar_fd(c, 1);
	}
	if (flags->minus_flag == 1)
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(ptr, 1);
	}
	free (ptr);
}

int	char_format(int c, t_flags *flags)
{
	int		len;

	len = flags->width_flag;
	if (flags->width_flag > 0)
		width_char(c, flags);
	else
	{
		ft_putchar_fd(c, 1);
		len = 1;
	}
	return (len);
}
