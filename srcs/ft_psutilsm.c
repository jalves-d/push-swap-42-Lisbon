#include "pushswap.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*to_find == 0)
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while ((to_find[j] == str[i + j]) && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_len(int *arr)
{
	size_t	size;

	size = sizeof(*arr) / sizeof(arr[0]);
	return (size);
}

int	printerror(void)
{
	write(1, "Error !\n", 8);
	return (0);
}

void	checklastwo(t_list *stacks)
{
	if (stacks->sA[stacks->size - 1] < stacks->sA[stacks->size - 2])
	{
		if (stacks->size > 2)
		{
			rra(stacks);
			pb(stacks);
			rra(stacks);
			pa(stacks);
			ra(stacks);
			ra(stacks);
		}
		else if (stacks->size == 2)
			ra(stacks);
	}
}
