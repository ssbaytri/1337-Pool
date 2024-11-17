#include <unistd.h>

int is_delimiter(char c)
{
    return (c == ' ' || c == '\t' || c == '\0');
}

char ft_to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

char ft_to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

void    str_capitalizer(char *str)
{
    int i;

    i = 0;
    int new_word = 1;
    while (str[i])
    {
        if (!is_delimiter(str[i]))
        {
            if (new_word)
                str[i] = ft_to_upper(str[i]);
            else
                str[i] = ft_to_lower(str[i]);
            new_word = 0;
        }
        else
            new_word = 1;
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        write(1, "\n", 1);
    else
    {
        int i;

        i = 1;
        while (i < argc)
        {
            str_capitalizer(argv[i]);
            ft_putstr(argv[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}