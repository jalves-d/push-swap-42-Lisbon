/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:47:00 by jalves-d          #+#    #+#             */
/*   Updated: 2021/09/13 12:53:28 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_first(t_list *stacks)
{
	int	i;

	i = 0;
	i = stacks->size;
	while (stacks->sb[i])
		i--;
	return (i);
}

int	find_last(t_list *stacks)
{
	int	i;

	i = 0;
	while (stacks->sa[i])
		i++;
	while (stacks->sa[i] == 0)
		i--;
	return (i);
}

void	ra(t_list *stacks)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = stacks->sa[0];
	last = find_last(stacks);
	while (i <= last)
	{
		stacks->sa[i] = stacks->sa[i + 1];
		i++;
	}
	stacks->sa[last] = j;
	ft_print("ra\n");
}

void	rb(t_list *stacks)
{
	int	first;
	int	i;

	first = stacks->sb[find_first(stacks) + 1];
	i = find_first(stacks) + 1;
	while (i <= stacks->size - 1)
	{
		stacks->sb[i] = stacks->sb[i + 1];
		i++;
	}
	stacks->sb[stacks->size] = first;
	ft_print("rb\n");
}

void	pb(t_list *stacks)
{
	int	i;
	int	temp;

	i = 0;
	temp = stacks->sa[0];
	if (temp == 0)
		exit(0);
	while (i <= stacks->size - 1)
	{
		stacks->sa[i] = stacks->sa[i + 1];
		i++;
	}
	stacks->sb[find_first(stacks)] = temp;
	ft_print("pb\n");
}
