/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   study.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:33:19 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/05/04 16:26:32 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main (void)
{	
	printf ("\nConversions: \n\n\t%%[flags][width][.precision]spercifier \n\n");

	printf("Specifiers: \n\n");
	char c = 'A';
	printf("%%c Prints a single character: %c \n", c);

	char s[] = "Hello World! \n";
	printf("%%s Prints a string: %s", s);

	char *p = "Fabio";
	printf("%%p The void * pointer argument printed in hexadecimal: %p \n", p);

	//int	d = 7031993;
	//printf("%%d Prints a decimal number: %d \n", d);

	int i = 7031993;
	printf("%%i Prints an integer in base 10: %i \n", i);

	int u = 7031993;
	printf("%%u Prints an unsigned decimal: %u \n", u);

	int	x = 7031993;
	printf("%%x Prints a number in hexadecimal lowercase format: %x \n", x);

	int X = 7031993;
	printf("%%X Prints a number in hexadecimal uppercase format: %X \n", X);

	printf("%%%% Prints a percent sign: %% \n");

	printf("\nBonus: \n\n");

	int d = 1;
	printf("%%-2c: |%-2c| \n", c);
	printf("%%2c: |%2c| \n", c);
	printf("%%#x: %#x \n", x);
	printf("%% d: % d \n", d);
	printf("%%02d: %02d \n", d);
	printf("%%+d: %+d \n", d);

}