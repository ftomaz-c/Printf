/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:03:05 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/09 18:35:11 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long long	address_value)
{
	int	len;

	len = 0;
	while (address_value != 0)
	{
		address_value /= 16;
		len++;
	}
	return (len);
}

static void	width_minus_flag(char *p, unsigned long long address_value, int minus_flag)
{
	if (minus_flag == 0)
	{
		ft_putstr_fd(p, 1);
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(address_value, "0123456789abcdef", 1);
	}
	else if (minus_flag == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(address_value, "0123456789abcdef", 1);
		ft_putstr_fd(p, 1);
	}
}

int			ptr_format(void *ptr, flag_data *flags)
{
	char				*p;
	int					len;
	int					width;
	unsigned long long	address_value;

	len = 0;
	address_value = (unsigned long long)ptr;
	len = ptr_len(address_value);
	width = flags->width_flag - len - 2;
	if (width > 0)
	{
		p = is_width_flag(width);
		width_minus_flag(p, address_value, flags->minus_flag);
		len += width;
		free(p);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(address_value, "0123456789abcdef", 1);

	}
	len += 2;
	return (len);
}
