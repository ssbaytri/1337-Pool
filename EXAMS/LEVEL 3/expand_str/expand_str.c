#include <unistd.h>

int ft_has_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\0');
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    white_spaces()
{
    write(1, "   ", 3);
}

void    expand_str(char *str)
{
    int first_w;
    int w_started;

    first_w = 1;
    w_started = 0;
    while (*str && ft_has_space(*str))
        str++;
    while (*str)
    {
        if (!ft_has_space(*str))
        {
            if (!first_w && !w_started)
                white_spaces();
            ft_putchar(*str);
            w_started = 1;
            first_w = 0;
        }
        // Handle spaces between words
        else if (w_started)
            w_started = 0;
        str++;
    }
}

int has_words(char *str)
{
    while (*str)
    {
        if (!ft_has_space(*str))
            return (1);
        str++;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2 || !has_words(av[1]))
    {
        write(1, "\n", 1);
        return (0);
    }

    expand_str(av[1]);
    write(1, "\n", 1);
    return (0);
}
