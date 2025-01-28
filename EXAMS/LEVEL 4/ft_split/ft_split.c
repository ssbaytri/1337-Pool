#include <stdio.h>
#include <stdlib.h>

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

// int main()
// {
// 	char *str = "hello wor d 		sakbd 	ajbsd";
// 	char **arr;
// 	arr = ft_split(str);
// 	for (int i = 0; i < word_count(str); i++)
// 	{
// 		printf("%s\n", arr[i]);
// 	}
// }