#include <stdio.h>
#include <stdlib.h>

int pgcd(int a, int b)
{
    int i = 1;
    int min = (a < b) ? a : b;
    while (min >= i)
    {
        if (a % min == 0 && b % min == 0)
            return min;
        min--;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int a = atoi(av[1]);
        int b = atoi(av[2]);
        printf("%d", pgcd(a, b));
    }
    printf("%c", '\n');
    return 0;
}