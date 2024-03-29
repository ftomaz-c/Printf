/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsg_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:23:09 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/24 16:19:43 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsg_format(unsigned int nbr)
{
	int	len;

	len = nbr_len(nbr);
	ft_putnbr_fd(nbr, 1);
	return (len);
}
