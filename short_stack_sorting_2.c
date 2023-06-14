/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack_sorting_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:10:22 by zbp15             #+#    #+#             */
/*   Updated: 2023/01/21 17:54:36 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	content_lenght5_part2(t_stack *s_a, t_stack *s_b, int i)
{
	if (i <= s_a->content_lenght / 2 && i > 0)
	{
		while (i--)
			rotate(s_a, 'a');
	}
	else if (i > 0)
	{
		i = i / 2;
		while (i--)
			reverse_rotate(s_a, 'a');
	}
	if (s_b->content_lenght - 1)
	{
		push(s_b, s_a, 'a', 0);
		content_lenght5_part2(s_a, s_b,
			find_small_but_big(s_a, s_b->content[0], -1, -1));
	}
	else
		content_lenght5_part3(s_a, s_b);
}

void	content_lenght5_part3(t_stack *stack_a, t_stack *stack_b)
{
	int	j;

	push(stack_b, stack_a, 'a', 0);
	j = find_small_but_big(stack_a, INT_MIN, -1, -1);
	if (--j < stack_a->content_lenght / 2)
	{
		while (!is_sorted(stack_a))
			rotate(stack_a, 'a');
	}
	else if (!is_sorted(stack_a))
	{
		while (!is_sorted(stack_a))
			reverse_rotate(stack_a, 'a');
	}
}
