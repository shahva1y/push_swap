#include "push_swap.h"
#include "./libft/libft.h"

static void	ft_error(char *error_messege)
{
	write(2, error_messege, ft_strlen(error_messege));
	exit(1);
}

static unsigned long long	ft_get_arguments_count(char ***arguments)
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

static char	***ft_collect_arguments(int argc, char **argv)
{
	char	***arguments;
	int		i;
	int		j;

	arguments = malloc(sizeof(char **) * (argc));
	if (!arguments)
		ft_error("Error\n");
	arguments[argc - 1] = NULL;
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		arguments[i] = (char **)ft_split(argv[i + 1], ' ');
		//
		if (!arguments[i])
			ft_error("Error\n");
		while (arguments[i][j])
			j++;
		i++;
	}
	return (arguments);
}

static int	*ft_to_int(unsigned long long count, char ***arguments)
{
	int	i;
	int	j;
	int	k;
	int	*tmp;

	i = 0;
	k = 0;
	tmp = malloc(sizeof(int) * (count));
	//
	if (!tmp)
		ft_error("Error\n");
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
	return (tmp);
}

int	main(int argc, char **argv)
{
	char				***arguments;
	unsigned int		*stack;
	int					*tmp;
	unsigned long long	length;

	if (argc > 1)
	{
		arguments = ft_collect_arguments(argc, argv);
		//
		if (!arguments)
			ft_error("Error\n");
		length = ft_get_arguments_count(arguments);
		stack = malloc(sizeof(unsigned int) * (length));
		if (!stack)
			ft_error("Error\n");
		tmp = ft_to_int(length, arguments);
		if (ft_duplicate_exist(tmp, length))
			ft_error("Error\n");
		ft_index(tmp, stack, length);
		push_swap(stack, length);
	}
	return (0);
}
