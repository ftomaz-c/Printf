/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:56:10 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/23 21:04:30 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int nbr_len(int nbr)
{
    int len;

    len = 0;
    if (nbr <= 0)
        len++;
    while (nbr != 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}

int format_nbr(int nbr)
{
    int len;

    len = nbr_len(nbr);
    ft_putnbr_fd(nbr, 1);
    return (len);
}