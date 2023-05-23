/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:53:48 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/23 20:13:38 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_str(char *str)
{
    int len;

    if (!str)
    {
        ft_putstr_fd("(null)", 1);
        return(6);
    }
    len = ft_strlen(str);
    ft_putstr_fd(str, 1);
    return (len);
}