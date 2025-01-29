#include <unistd.h>
#include <stdlib.h>

char ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c -= 32;
    return c;
}

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int count_under(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] == '_')
            count++;
        i++;
    }
    return count;
}

char *ft_snake_to_camel(char *str)
{
    char *res;
    int i = 0;
    int j = 0;
    int len = ft_strlen(str);
    int count = count_under(str);
    res = malloc(len - count + 1);
    if (!res)
        return NULL;
    while (str[i])
    {
        if (str[i] && str[i] != '_')
        {
            res[j++] = str[i];
        }
        else if (str[i] == '_')
        {
            i++;
            if (str[i])
                res[j++] = ft_toupper(str[i]);
        }
        i++;
    }
    res[j] = 0;
    return res;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        char *str = ft_snake_to_camel(av[1]);
        write(1, str, ft_strlen(str));
        free(str);
    }
    write(1, "\n", 1);
    return 0;
}