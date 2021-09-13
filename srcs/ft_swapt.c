/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:47:07 by jalves-d          #+#    #+#             */
/*   Updated: 2021/09/13 12:54:42 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list *stacks)
{
	int	temp;

	temp = stacks->sa[0];
	if (stacks->sa[1] == 0)
		return ;
	stacks->sa[0] = stacks->sa[1];
	stacks->sa[1] = temp;
	ft_print("sa\n");
}

void	sb(t_list *stacks)
{
	int	temp;

	temp = stacks->sb[find_first(stacks) + 1];
	stacks->sb[find_first(stacks) + 1] = stacks->sb[find_first(stacks) + 2];
	stacks->sb[find_first(stacks) + 2] = temp;
	ft_print("sb\n");
}

void	rra(t_list *stacks)
{
	int	i;
	int	j;
	int	last;

	last = find_last(stacks);
	i = last;
	j = stacks->sa[last];
	while (i > 0)
	{
		stacks->sa[i] = stacks->sa[i - 1];
		i--;
	}
	stacks->sa[0] = j;
	ft_print("rra\n");
}

void	rrb(t_list *stacks)
{
	int	i;
	int	j;

	j = stacks->sb[stacks->size];
	i = stacks->size;
	while (i > 0)
	{
		stacks->sb[i] = stacks->sb[i - 1];
		i--;
	}
	stacks->sb[find_first(stacks)] = j;
	ft_print("rrb\n");
}

void	pa(t_list *stacks)
{
	int	i;
	int	save;

	save = stacks->sb[find_first(stacks) + 1];
	if (save == 0)
		return ;
	stacks->sb[find_first(stacks) + 1] = 0;
	i = stacks->size;
	while (i > 0)
	{
		stacks->sa[i] = stacks->sa[i - 1];
		i--;
	}
	stacks->sa[i] = save;
	ft_print("pa\n");
}
