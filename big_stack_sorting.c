/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:38:27 by rciaze            #+#    #+#             */
/*   Updated: 2023/01/21 17:43:13 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	content_lenght20(t_stack *stack_a, t_stack *stack_b, int i, int j)
{
	push(stack_a, stack_b, 'b', 0);
	if (stack_a->content_lenght)
		i = find_place(stack_b, stack_a->content[0], -1);
	if (stack_a->content_lenght)
	{
		if (i <= stack_b->content_lenght / 2 && i > 0)
		{
			while (i--)
				rotate(stack_b, 'b');
		}
		else if (i > 0)
		{
			i = stack_b->content_lenght - i;
			while (i--)
				reverse_rotate(stack_b, 'b');
		}
	}
	if (--j)
		content_lenght20(stack_a, stack_b, 0, j);
}

void	content_lenght20_part_2(t_stack *stacka, t_stack *stackb, int i, int j)
{
	if (i <= stackb->content_lenght / 2 && i > 0)
	{
		while (i--)
			rotate(stackb, 'b');
	}
	else if (i > 0)
	{
		i = stackb->content_lenght - i;
		while (i--)
			reverse_rotate(stackb, 'b');
	}
	i = stackb->content_lenght;
	while (i--)
		push(stackb, stacka, 'a', 0);
	while (j--)
		rotate(stacka, 'a');
}
