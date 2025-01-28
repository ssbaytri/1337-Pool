#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_ischar(int c)
{
	return (c == ' ' || c == '\n' || c == '\0' || c == '\t');
}

int word_count(char *str)
{
	int count = 0;
	int i = 0;
	while (str[i])
	{
		while (str[i] &&ft_ischar(str[i]))
			i++;
		if (!ft_ischar(str[i]))
			count++;
		while (!ft_ischar(str[i]))
			i++;
	}
	return count;
}


int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] && !ft_ischar(str[i]))
		i++;
	return i;
}

char *ft_word(char *str)
{
	char *word;
	int word_len;
	int i;

	i = 0;
	word_len = ft_strlen(str);
	word = malloc(word_len + 1);
	if (!word)
		return NULL;
	while (i < word_len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return word;
}


char    **ft_split(char *str)
{
	char **result;
	int i;

	i = 0;
	result = malloc(sizeof(char *) * word_count(str) + 1);
	if (!result)
		return NULL;
	while (*str)
	{
		while (*str && ft_ischar(*str))
			str++;
		if (*str)
		{
			result[i] = ft_word(str);
			i++;
		}
		while (*str && !ft_ischar(*str))
			str++;
	}
	result[i] = NULL;
	return result;
}

void	ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return 1;
	}
	int i = 0;
	int wc = word_count(av[1]);
	char **arr = ft_split(av[1]);
	if (ac > 1)
	{
		for (int j = 1; j < wc; j++)
		{
			ft_putstr(arr[j]);
			write(1, " ", 1);
		}	
	}ft_putstr(arr[0]);
	write(1, "\n", 1);
}