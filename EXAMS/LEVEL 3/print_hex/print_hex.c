#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	sign = 1; 


	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void    print_hex(int n)
{
    if (n >= 16)
        print_hex(n / 16);
    ft_putchar("0123456789abcdef"[n % 16]);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putchar('\n');
        return (0);
    }
    print_hex(ft_atoi(argv[1]));
    ft_putchar('\n');
    return (0);
}
