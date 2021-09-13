/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:46:24 by jalves-d          #+#    #+#             */
/*   Updated: 2021/09/13 12:50:17 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort(int size, int *array)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

int	find_big(t_list *stacks)
{
	int	i;
	int	big;

	i = 0;
	big = INT_MIN;
	while (i <= stacks->size)
	{
		if (big <= stacks->sb[i] && stacks->sb[i] != 0)
			big = stacks->sb[i];
		i++;
	}
	i = 0;
	while (i <= stacks->size)
	{
		if (big == stacks->sb[i])
			return (i);
		i++;
	}
	return (0);
}

int	find_small(t_list *stacks)
{
	int	i;
	int	small;

	i = 0;
	small = stacks->sa[i];
	while (i <= stacks->size)
	{
		if (small > stacks->sa[i] && stacks->sa[i] != 0)
			small = stacks->sa[i];
		i++;
	}
	return (small);
}

int	check_dup(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strlen(argv[i]) == ft_strlen(argv[j]))
			{
				if (ft_strnstr(argv[i], argv[j], ft_strlen(argv[i])))
				{
					ft_print("Error\n");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_char(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
			{
				ft_print("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
