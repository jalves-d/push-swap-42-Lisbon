#include "pushswap.h"

int	ft_mop(t_list *stacks, int cnum)
{
	int	*astack;
	int	middle;
	int	ssize;

	ssize = sizes(stacks, 'a');
	if (cnum == 10)
		ssize = stacks->size;
	astack = ft_calloc(ssize, sizeof(int));
	ft_memcpy(astack, stacks->sA, sizeof(int) * ssize);
	ft_sort(ssize, astack);
	if (cnum == 10)
	{
		stacks->ch = stacks->ch + (ssize / 10);
		if (stacks->ch < ft_len(astack))
			middle = astack[stacks->ch];
		else
			middle = astack[stacks->ch - 1];
	}
	else
	{
		middle = ssize / 2;
		middle = astack[middle];
	}
	return (middle);
}

int	ft_hl(t_list *stacks, int mid)
{
	int	i;

	i = 0;
	while (i < stacks->size)
	{
		if (stacks->sA[i] < mid && stacks->sA[i] != 0)
		{
			stacks->pos = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	sizes(t_list *stacks, char st)
{
	int	i;
	int	cont;

	i = -1;
	cont = 0;
	if (st == 'a')
	{
		while (i++ < stacks->size)
			if (stacks->sA[i])
				cont++;
		return (cont);
	}
	else
	{
		while (i++ < stacks->size)
			if (stacks->sB[i])
				cont++;
		return (cont);
	}
}

int	ft_checkord(t_list *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size - 1)
	{
		if (stacks->sA[i] > stacks->sA[i + 1])
			return (1);
		i++;
	}
	free(stacks->sA);
	free(stacks->sB);
	return (0);
}
