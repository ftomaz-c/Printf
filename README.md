# Printf

Write a library that contains ft_printf(), a function that will mimic the original printf()!

## Things to understand

* [man printf()](https://man7.org/linux/man-pages/man3/printf.3.html)
* Why does printf can receive infinite arguments? :heavy_check_mark:
* How to display the % sign?
* Variadic functions :heavy_check_mark:
    * va_start, va_arg, va_copy, va_end
* Buffer management
* Conversions: cspdiuxX% (placeholders)
* [Array of function pointer](http://www.java2s.com/Code/C/Function/Arrayoffunctionpointer.htm)
* stdarg.h
    * [man stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html)
* [man atributes(7)](https://man7.org/linux/man-pages/man7/attributes.7.html)
* [Variable arguments in Objective-C methods](https://developer.apple.com/library/archive/qa/qa1405/_index.html)

## Intructions

### Prototype

```int  ft_printf(const char *, ...);```

### Requirements

> Here are the requirements:
>* Don’t implement the buffer management of the original printf().
>* Your function has to handle the following conversions: cspdiuxX%
>* Your function will be compared against the original printf().
>* You must use the command ar to create your library. Using the libtool command is forbidden.
>* Your libftprintf.a has to be created at the root of your repository.

### Conversions

```%[flags][width][.precision]specifier```

The following conversions must be implemented:

* %c Prints a single character.
* %s Prints a string (as defined by the common C convention).
* %p The void * pointer argument has to be printed in hexadecimal format.
* %d Prints a decimal (base 10) number.
* %i Prints an integer in base 10.
* %u Prints an unsigned decimal (base 10) number.
* %x Prints a number in hexadecimal (base 16) lowercase format.
* %X Prints a number in hexadecimal (base 16) uppercase format.
* %% Prints a percent sign.

## Bonus

### Requirements

>* Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions;
>* Manage all the following flags: ’# +’ (Yes, one of them is a space).

### Conversions

```%[flags][width][.precision]specifier```

* -: left-justify the output within the specified field width.
* 0: pad the output with leading zeros instead of spaces.
* .: specify the precision for a floating-point conversion or the maximum number of characters to print for a string conversion.
* #: used with the o, x, or X conversion specifiers, to prefix the output with 0 for o, or 0x or 0X for x or X respectively.
* +: used with the d, i, f, e, or E conversion specifiers, to always include a sign (+ or -) in the output.
* ' ' (space): used with the d, i, f, e, or E conversion specifiers, to insert a space before positive numbers, instead of the + sign.

#### Considerations

* The 0 flag is overridden by the - flag. If both flags are present, the - flag takes precedence and the 0 flag is ignored.
* The + and ' ' (space) flags are mutually exclusive. If both flags are present, the + flag takes precedence and the ' ' flag is ignored.
* The # flag is ignored if the conversion specifier is d, i, u, or c. It is also ignored if the conversion specifier is o and the precision is zero.
* The 0 flag is ignored if the conversion specifier is d, i, u, c, s, p, or n, or if the - flag is present.
* The . (precision) flag overrides the 0 flag if both are present. If the . flag is present with a precision of zero, no characters are printed for the conversion specifier.
* The 0 flag is ignored for non-numeric conversion specifiers, such as s, c, p, or n.

!!![width] - includes the number of characters in the input.

!If you plan to complete the bonus part, think about the implementation of your extra features from the start. This way, you will avoid the pitfalls of a naive approach.!