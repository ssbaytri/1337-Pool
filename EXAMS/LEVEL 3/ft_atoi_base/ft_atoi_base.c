int ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int ft_isvalid(char c, int base)
{
	char digits[16] = "0123456789ABCDEF";
	char digits2[16] = "0123456789abcdef";
	while (base--)
	{
		if (c == digits[base] || c == digits2[base])
			return (1);
	}
	return (0);
}

int ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return 0;
}
int     ft_atoi_base(const char *str, int str_base)
{
	int res = 0;
	int sign;

	while (ft_isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : 0;
	while (ft_isvalid(*str, str_base))
	{
		res = res * str_base + ft_value_of(*str);
		str++;
	}
	return (res * sign);
}
