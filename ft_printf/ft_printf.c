#include <unistd.h>
#include <stdarg.h>

void    ft_putstr(char *s, int *d)
{
    if(!s)
        s = "(null)";
    while(*s)
    {
        write(1, s++, 1);
        (*d)++;
    }
}

void    ft_putnbr(int n, int *d)
{
    char c;
    
    if(n == -2147483648)
    {
        ft_putstr("-2147483648", d);
        return;
    }
    if(n < 0)
    {
        write(1, "-", 1);
        (*d)++;
        n = -n;
    }
    if(n > 9)
        ft_putnbr(n / 10, d);

    c = n % 10 + 48;
    write(1, &c, 1);
    (*d)++;
}

void    ft_puthex(unsigned int n, int *d)
{
    char hex[] = "0123456789abcdef";
    if (n >= 16)
        ft_puthex(n / 16, d);
    write (1, &hex[n % 16], 1);
    (*d)++;
}

int ft_printf(const char *format, ... )
{
    va_list ap;
    int d = 0;

    va_start(ap, format);
    while(*format)
    {
        if(*format == '%' && *(format + 1))
        {
            format++;
            if(*format == 's')
                ft_putstr(va_arg(ap, char *), &d);
            else if (*format == 'd')
                ft_putnbr(va_arg(ap, int), &d);
            else if (*format == 'x')
                ft_puthex(va_arg(ap, unsigned int), &d);
            else
            {
                write(1, format, 1);
                d++;
            }
        }
        else
        {
            write(1, format, 1);
            d++;
        }
        format++;
    }
    va_end(ap);
    return(d);

}

#include <stdio.h>
int main(void)
{
    printf("Hello %s, %d, %x\n", "world", -42, 255);
    ft_printf("Hello %s, %d, %x\n", "world", -42, 255);
    return (0);
}