/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:19:43 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/26 13:05:39 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);

int	str_format(char *str);
int	ptr_format(void *ptr);
int	nbr_format(int nbr);
int	unsg_format(unsigned int nbr);
int	hex_format(unsigned int hex, const char *format);

int	nbr_len(long nbr);
int	ptr_len(unsigned long nbr);
int	hex_len(unsigned int nbr);

#endif
