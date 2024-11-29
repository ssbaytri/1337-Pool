unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int max;
    unsigned int multiple;

    if (a == 0 || b == 0)
        return 0;
    if (a > b)
        max = a;
    else
        max = b;
    multiple = max;
    while (1)
    {
        if (multiple % a == 0 && multiple % b == 0)
            return multiple;
        multiple += max;
    }
}
