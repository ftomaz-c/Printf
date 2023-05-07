/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:49:19 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/07 17:05:31 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Iterate through the input until a % sign appears. Write everything
encountered before that point.
2. Once a % sign is found, check if there are any flags present.
3. If a flag is found, handle it accordingly by performing the required
action or modification.
4. Check if there are subsequent flags that may cancel or modify the effect
of the previous flag. Adjust the behavior based on these flags if necessary.
5. For specific flags (e.g., -), check if there are additional parameters
(such as a number) following the flag. Use these parameters to determine the
behavior of the flag.
6. Once all flags have been processed, identify and handle the placeholder.
7.Continue iterating through the input to check if there are any more
occurrences of % signs with flags and placeholders. Repeat steps 2-6 as
necessary.
*/

#include "printf.h"

int ft_printf(const char *format, ...)
{
    int flags;

    if (!format)
        return 0;
    flags = flag_check(format);

    printf("ft_printf:\n");
    printf("Format: %s\n", format);
    printf("Flags: %u\n", flags);
    printf("------------------------------\n");

    return 0;
}

int main()
{
    const char *format = "%+";
    int flags = flag_check(format);

    printf("Flags:\n");
    printf("Format: %s\n", format);
    printf("Flags: %u\n", flags);
    printf("------------------------------\n");

    ft_printf(format);

    return 0;
}
