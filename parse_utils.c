#include "push_swap.h"

/*
 * ПРЕДСТАВЛЕНИЕ ЧИСЕЛ
 * Какой формат ввода числа считается представимым?
 * 1. Символ '-' ставится только 1 раз. Знак '+' не ставится. (?)
 * 2. Могу встречаться только символы цифр и знака '-' перед числом.
 * 3. Число не должно вызывать переполнение int.
 * 4. (...)
 */

int	ft_duplicate_exist(int *tmp, unsigned int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < i)
		{
			if (tmp[i] == tmp[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_index(int *tmp, unsigned int *stack, unsigned int length)
{
	int				i;
	int				j;
	unsigned int	value;

	i = 0;
	while (i < length)
	{
		value = 0;
		j = 0;
		while (j < length)
		{
			if (tmp[j] < tmp[i])
				value++;
			j++;
		}
		stack[i] = value;
		i++;
	}
	free(tmp);
}

int	ft_is_representable(char *str)
{
	int				i;
	unsigned int	length;
	char			*int_max;
	char			*int_min;

	i = 0;
	int_max = "2147483647";
	int_min = "-2147483648";
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (str[0] == '-' && i == 1)
		return (0);
	length = ft_strlen(str);
	if ((length > 10 && str[0] != '-')
		|| (length > 11 && str[0] == '-'))
		return (0);
	if ((length < 10 && str[0] != '-')
		|| (length < 11 && str[0] == '-'))
		return (1);
	if ((str[0] != '-' && ft_strncmp(str, int_max, 10) > 0)
		|| (str[0] == '-' && ft_strncmp(str, int_min, 11) > 0))
		return (0);
	return (1);
}
