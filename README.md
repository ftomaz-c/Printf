# Printf

Write a library that contains ft_printf(), a function that will mimic the original printf()!

## Things to understand

* [man printf();](https://man7.org/linux/man-pages/man3/printf.3.html)
* Why does printf can receive infinite arguments?;
* How to display the % sign?;
* Variadic functions;
    * va_start, va_arg, va_copy, va_end
* Buffer management;
* Conversions: cspdiuxX%;
* [Array of function pointer;](http://www.java2s.com/Code/C/Function/Arrayoffunctionpointer.htm)
* [man stdarg(3);](https://man7.org/linux/man-pages/man3/stdarg.3.html)
* [man atributes(7);](https://man7.org/linux/man-pages/man7/attributes.7.html)
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

### Bonus

>* Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions;
>* Manage all the following flags: ’# +’ (Yes, one of them is a space).

If you plan to complete the bonus part, think about the implementation of your extra features from the start. This way, you will avoid the pitfalls of a naive approach.