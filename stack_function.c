/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:07:22 by zbp15             #+#    #+#             */
/*   Updated: 2023/01/21 18:20:06 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap(t_stack *stack, char c)
{
	int	temp;

	ft_printf("s%c\n", c);
	if (stack->content_lenght < 2)
		return ;
	temp = stack->content[0];
	stack->content[0] = stack->content[1];
	stack->content[1] = temp;
}

void	rotate(t_stack *stack, char c)
{
	int	temp;
	int	temp2;
	int	i;

	if (stack->content_lenght < 2)
		return ;
	i = 0;
	temp2 = stack->content[i];
	while (i < stack->content_lenght - 1)
	{
		temp = stack->content[i];
		stack->content[i] = stack->content[i + 1];
		stack->content[i + 1] = temp;
		i++;
	}
	stack->content[stack->content_lenght - 1] = temp2;
	ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stack *stack, char c)
{
	int	temp;
	int	temp2;
	int	i;

	if (stack->content_lenght < 2)
		return ;
	i = stack->content_lenght - 1;
	temp2 = stack->content[stack->content_lenght - 1];
	while (0 < i)
	{
		temp = stack->content[i];
		stack->content[i] = stack->content[i - 1];
		stack->content[i - 1] = temp;
		i--;
	}
	stack->content[i] = temp2;
	ft_printf("rr%c\n", c);
}

void	push(t_stack *stack_a, t_stack *stack_b, char c, int i)
{
	int	*content_a;
	int	*content_b;
	int	temp;

	content_a = ft_calloc(sizeof(int), stack_a->content_lenght - 1);
	if (!content_a)
		return (free(stack_a->content), free(stack_a), free(stack_b->content),
			free(stack_b), exit (0));
	content_b = ft_calloc(sizeof(int), stack_b->content_lenght + 1);
	if (!content_b)
		return (free(stack_a->content), free(stack_a), free(stack_b->content),
			free(stack_b), free(content_a), exit (0));
	temp = stack_a->content[0];
	while (++i < stack_a->content_lenght)
		content_a[i - 1] = stack_a->content[i];
	stack_a->content_lenght -= 1;
	i = -1;
	while (++i < stack_b->content_lenght)
		content_b[i + 1] = stack_b->content[i];
	content_b[0] = temp;
	ft_printf("p%c\n", c);
	push2(stack_a, stack_b, content_a, content_b);
}

void	push2(t_stack *s_a, t_stack *s_b, int *content_a, int *content_b)
{
	s_b->content_lenght += 1;
	free(s_a->content);
	free(s_b->content);
	s_a->content = content_a;
	s_b->content = content_b;
}
