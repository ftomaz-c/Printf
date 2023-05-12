#include "ft_printf.h"
#include <limits.h>

/* int main()
{
	char *s =  "percentagem";
	ft_printf("\n\n%% :%%%s\n", s);
	return(0);
} */

/*int main()
{
	int number = 42;

	ft_printf("\nNumber: %d|\n\n", number);
	ft_printf("Number with width: %5d|\n\n", number);
	ft_printf("Number with zero padding: %05d|\n\n", number);
	ft_printf("Number with left alignment: %-5d|\n\n", number);
	ft_printf("Number with plus flag: %+d|\n\n", number);
	ft_printf("Number with space flag: % d|\n\n", number);
	ft_printf("Number with precision: %.2d|\n\n", number);

	int negative_number = -123;

	ft_printf("Negative number: %d|\n\n", negative_number);
	ft_printf("Negative number with width: %8d|\n\n", negative_number);
	ft_printf("Negative number with zero padding: %010d|\n\n", negative_number);
	ft_printf("Negative number with left alignment: %-8d|\n\n", negative_number);
	ft_printf("Negative number with plus flag: %+d|\n\n", negative_number);
	ft_printf("Negative number with space flag: % d|\n\n", negative_number);
	ft_printf("Negative number with precision: %.3d|\n\n", negative_number);

	int zero = 0;

	ft_printf("Zero: %d|\n\n", zero);
	ft_printf("Zero with width: %5d|\n\n", zero);
	ft_printf("Zero with zero padding: %08d|\n\n", zero);
	ft_printf("Zero with left alignment: %-5d|\n\n", zero);
	ft_printf("Zero with plus flag: %+d|\n\n", zero);
	ft_printf("Zero with space flag: % d|\n\n", zero);
	ft_printf("Zero with precision: %.1d|\n\n", zero);

	return (0);
}*/

int	main()
{
	int		len;

	ft_printf("\n\n\n\nTesting ft_printf:\n\n");
	len = ft_printf("%5%");
	printf ("\nLength: %d\n", len);
	printf ("\n-------------------------\n");
/* 	printf("\nTesting printf:\n\n");
	len = printf("%5%");
	printf("\nLength: %d\n\n", len); */

	return (0);
}
