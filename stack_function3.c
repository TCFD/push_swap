/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:32:50 by rciaze            #+#    #+#             */
/*   Updated: 2023/01/21 18:20:12 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	find_place(t_stack *stack, int n, int i)
{
	int	is_biggest;
	int	is_smallest;

	is_biggest = 1;
	is_smallest = 1;
	while ((is_biggest || is_smallest) && ++i < stack->content_lenght)
	{
		if (n < stack->content[i])
			is_biggest = 0;
		if (n > stack->content[i])
			is_smallest = 0;
	}
	if (is_biggest || is_smallest)
		return (find_biggest(stack));
	return (find_bigger_but_smaller(stack, n));
}

int	find_biggest(t_stack *stack)
{
	int	i;
	int	k;
	int	j;

	i = -1;
	k = INT_MIN;
	j = -1;
	while (++i < stack->content_lenght)
	{
		if (k < stack->content[i])
		{
			k = stack->content[i];
			j = i;
		}
	}
	return (j);
}

int	find_bigger_but_smaller(t_stack *stack, int n)
{
	int	i;
	int	j;
	int	k;

	k = INT_MIN;
	i = -1;
	j = -1;
	while (++i < stack->content_lenght)
	{
		if (k < stack->content[i] && stack->content[i] < n)
		{
			k = stack->content[i];
			j = i;
		}
	}
	return (j);
}
