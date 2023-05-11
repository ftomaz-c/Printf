/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:03:05 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/11 01:35:00 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_base_len(char *base, long long nbr)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr <= 0)
		len += 1;
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

static void	width_ptr_flag(char *p, long long address_value, int minus_flag)
{

	char	*base;

	base = "0123456789abcdef";
	if (minus_flag == 0)
	{
		ft_putstr_fd(p, 1);
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(address_value, base, 1);
	}
	else if (minus_flag == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(address_value, base, 1);
		ft_putstr_fd(p, 1);
	}
}

int	ptr_format(void *ptr, t_flag_data *flags)
{
	char				*p;
	int					len;
	int					width;
	unsigned long long	address_value;
	char				*base;

	len = 0;
	base = "0123456789abcdef";
	address_value = (unsigned long long)ptr;
	len = nbr_base_len(base, address_value);
	width = flags->width_flag - len - 2;
	if (width > 0)
	{
		p = is_width_flag(width);
		width_ptr_flag(p, address_value, flags->minus_flag);
		len += width;
		free(p);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(address_value, base, 1);
	}
	len += 2;
	return (len);
}
