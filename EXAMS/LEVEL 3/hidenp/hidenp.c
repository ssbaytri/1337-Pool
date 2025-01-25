#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while (s2[i])
	{
		if (s1[j] == s2[i])
			j++;
		i++;
	}
	if (s1[j] == 0)
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	hidenp(av[1], av[2]);
}