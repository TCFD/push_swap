/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:01:36 by zbp15             #+#    #+#             */
/*   Updated: 2023/01/24 14:43:25 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	content_lenght;
	int	*content;
}	t_stack;

void	swap(t_stack *stack, char c);
void	rotate(t_stack *stack, char c);
void	reverse_rotate(t_stack *stack, char c);
void	push(t_stack *a_stack, t_stack *b_stack, char c, int i);
void	push2(t_stack *s_a, t_stack *s_b, int *content_a, int *content_b);
int		is_sorted(t_stack *stack);
void	aguillage(t_stack *stack_a, t_stack *stack_b);
void	aguillage_le_retour(t_stack *stack_a, t_stack *stack_b);
void	content_lenght2(t_stack *stack, char c);
void	content_lenght3(t_stack *stack);
void	content_lenght3_part2(t_stack *stack);
void	content_lenght5(t_stack *s_a, t_stack *s_b);
void	content_lenght5_part2(t_stack *s_a, t_stack *s_b, int i);
void	content_lenght5_part3(t_stack *stack_a, t_stack *stack_b);
void	get_stack(t_stack *stack, int argc, char **argv);
int		is_number_valid(char *str, int i);
void	is_stack_valid(t_stack *stack);
int		find_small_but_big(t_stack *stack, int n, int j, int k);
int		find_place(t_stack *stack, int n, int i);
int		find_biggest(t_stack *stack);
int		find_bigger_but_smaller(t_stack *stack, int n);
void	content_lenght20(t_stack *stack_a, t_stack *stack_b, int i, int j);
void	content_lenght20_part_2(t_stack *stacka, t_stack *stackb, int i, int j);
void	split(t_stack *stack_a, t_stack *stack_b);
#endif