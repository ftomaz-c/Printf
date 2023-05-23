/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:16:26 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/23 20:55:34 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int 	hex_len(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len += 5;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int format_ptr(void *ptr)
{
    unsigned long long	address_value;
    int					len;

    address_value = (unsigned long)ptr;
    len = hex_len(address_value);
    if (address_value == 0)
        ft_putstr_fd("(nil)", 1);
    else
    {
        ft_putstr_fd("0x", 1);
        ft_putnbr_base_fd(address_value, "0123456789abcdef", 1);
        len += 2;
    }
    return (len);
}