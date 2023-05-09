/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:19:43 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/09 18:38:56 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct
{
    char	minus_flag;
	char	zero_flag;
	int		width_flag;
    int		precision_flag;
	char	*alternative_form;
	char	space;
	char	plus;
} flag_data;

/* printf */
int			ft_printf(const char *format, ...);

/* flags */
flag_data	*flag_check(const char *format);
char		minus_flag (const char *format);
char		zero_flag (const char *format);
int			width_flag (const char *format);
int			precision_flag(const char *format);
char		*alternative_form(const char *format);

/* formating */
char		is_placeholder(const char *format);
char		*is_width_flag(int len);
int			format_specifier(const char *format, va_list args, flag_data *flags);
int			str_format(char *s, flag_data *flags);
int			ptr_format(void *ptr, flag_data *flags);

#endif
