/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:19:43 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/07 17:11:25 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef enum {
    FLAG_NONE = 0,
    FLAG_MINUS = 1,
    FLAG_ZERO = 2,
    FLAG_DOT = 3,
    FLAG_HASH = 4,
    FLAG_SPACE = 5,
    FLAG_PLUS = 6
} Flag;

Flag flag_check(const char *format);

#endif
