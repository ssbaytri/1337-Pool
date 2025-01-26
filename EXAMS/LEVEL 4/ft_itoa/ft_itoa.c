// #include <stdio.h>
#include <stdlib.h>

int ft_len(int nb)
{
	int len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return len;
}

char	*ft_itoa(int nbr)
{
	char *result;
	int i = 0;
	int len = ft_len(nbr);

	result = malloc(len + 1);
	if (!result)
		return NULL;
	result[len] = '\0';
	if (nbr == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		nbr =  147483648;
	}
	if (nbr == 0)
	{
		result[0] = '0';
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	while (nbr != 0)
	{
		result[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return result;
}

// int main()
// {
// 	printf("%s\n", ft_itoa(-0));
// }