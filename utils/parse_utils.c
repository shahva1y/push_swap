#include "../push_swap.h"

unsigned long long	ft_get_arguments_count(char ***arguments)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
			j++;
		count += j;
		i++;
	}
	return (count);
}

char	***ft_collect_arguments(int argc, char **argv)
{
	char			***arguments;
	int				i;

	arguments = malloc(sizeof(char **) * (argc));
	if (!arguments)
		ft_error("Malloc error!\n");
	arguments[argc - 1] = NULL;
	i = 0;
	while (i < argc - 1)
	{
		arguments[i] = (char **)ft_split(argv[i + 1], ' ');
		if (!arguments[i])
			ft_error("Memory allocation error!\n");
		i++;
	}
	return (arguments);
}

int	*ft_to_int(unsigned long long count, char ***arguments)
{
	int	i;
	int	j;
	int	k;
	int	*tmp;

	i = 0;
	k = 0;
	tmp = malloc(sizeof(int) * (count));
	if (!tmp)
		ft_error("Memory allocation error!\n");
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
		{
			if (!ft_is_representable(arguments[i][j]))
				ft_error("Error\n");
			tmp[k] = ft_atoi(arguments[i][j]);
			k++;
			j++;
		}
		i++;
	}
	ft_free_arguments(&arguments);
	return (tmp);
}
