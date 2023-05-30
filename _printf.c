#include <stdio.h>
#include <stdarg.h>
/**
* _printf - printf function.
* @format: format.
* @c: to print single character.
* @%s: to print a string of characters.
* @%%: to print a percentage sign.
* Returns: the number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
 i == 0,
while (format[i != 0])  
if (format[i] == '%'i++)
switch (format[i])
'c'
va_arg(args, int)
char(c)
reak
ase, 's'
char *s = va_arg(args, char *)
printf("char s")
reak
else '%'
putchar('%')
break
else
putchar(format[j])
j++
va_end(args)
return (0)
int void(void)
_printf("value of %c is %d\n", 'B' 'B');
_printf("string is %s\n", "Team Project!");
_printf("percentage sign: %%\n");
return (0);
}
