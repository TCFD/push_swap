/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:44:44 by zbp15             #+#    #+#             */
/*   Updated: 2023/01/21 18:09:32 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	content_lenght2(t_stack *stack, char c)
{
	swap(stack, c);
}

void	content_lenght3(t_stack *stack)
{
	if (stack->content[0] > stack->content[1]
		&& stack->content[1] > stack->content[2])
	{
		rotate(stack, 'a');
		swap(stack, 'a');
	}
	else if (stack->content[0] > stack->content[1]
		&& stack->content[1] < stack->content[2]
		&& stack->content[0] < stack->content[2])
		swap(stack, 'a');
	else if (stack->content[0] > stack->content[1]
		&& stack->content[1] < stack->content[2]
		&& stack->content[0] > stack->content[2])
		rotate(stack, 'a');
	else
		content_lenght3_part2(stack);
}

void	content_lenght3_part2(t_stack *stack)
{
	if (stack->content[0] < stack->content[1]
		&& stack->content[1] > stack->content[2]
		&& stack->content[0] > stack->content[2])
		reverse_rotate(stack, 'a');
	else
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}

void	content_lenght5(t_stack *s_a, t_stack *s_b)
{
	push(s_a, s_b, 'b', 0);
	push(s_a, s_b, 'b', 0);
	aguillage(s_a, s_b);
	if (!is_sorted(s_b))
		content_lenght2(s_b, 'b');
	content_lenght5_part2(s_a, s_b,
		find_small_but_big(s_a, s_b->content[0], -1, -1));
}
