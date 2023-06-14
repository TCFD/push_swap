/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:46:21 by zbp15             #+#    #+#             */
/*   Updated: 2023/01/23 16:59:57 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	if (stack_a == NULL)
		return (0);
	stack_a->content_lenght = argc - 1;
	stack_a->content = ft_calloc(sizeof(int), stack_a->content_lenght);
	if (stack_a->content == NULL)
		return (free(stack_a), 0);
	get_stack(stack_a, argc, argv);
	stack_b = ft_calloc(sizeof(t_stack), 1);
	if (stack_b == NULL)
		return (free(stack_a->content), free(stack_a), 0);
	stack_b->content = ft_calloc(sizeof(int), 0);
	if (stack_b->content == NULL)
		return (free(stack_a->content), free(stack_a), free(stack_b), 0);
	stack_b->content_lenght = 0;
	aguillage(stack_a, stack_b);
	free(stack_a->content);
	free(stack_a);
	free(stack_b->content);
	free(stack_b);
	return (0);
}

void	aguillage(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->content_lenght == 1 || is_sorted(stack_a))
		return ;
	else if (stack_a->content_lenght == 2)
		content_lenght2(stack_a, 'a');
	else if (stack_a->content_lenght == 3)
		content_lenght3(stack_a);
	else if (stack_a->content_lenght <= 5)
		content_lenght5(stack_a, stack_b);
	else if (stack_a->content_lenght <= 42)
	{
		content_lenght20(stack_a, stack_b, 0, stack_a->content_lenght);
		content_lenght20_part_2(stack_a, stack_b, find_biggest(stack_b), 0);
	}
	else if (stack_a->content_lenght)
		aguillage_le_retour(stack_a, stack_b);
}

void	aguillage_le_retour(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	if (stack_a->content_lenght <= 100)
		j = 4;
	else
		j = 11;
	i = stack_a->content_lenght / j;
	j--;
	while (j--)
	{
		content_lenght20(stack_a, stack_b, 0, i);
		content_lenght20_part_2(stack_a, stack_b, find_biggest(stack_b), i);
	}
	content_lenght20(stack_a, stack_b, 0, i);
	content_lenght20(stack_a, stack_b, 0, stack_a->content_lenght);
	content_lenght20_part_2(stack_a, stack_b, find_biggest(stack_b), 0);
}
