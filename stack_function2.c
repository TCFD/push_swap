/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:51:17 by zbp15             #+#    #+#             */
/*   Updated: 2023/02/02 14:34:31 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (++i < stack->content_lenght)
	{
		if (stack->content[i - 1] > stack->content[i])
			return (0);
	}
	return (1);
}

int	is_number_valid(char *str, int i)
{
	long long int	value;
	int				boolean;

	value = 0;
	boolean = 0;
	if (str[i] == '-')
	{
		boolean = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		value *= 10;
		value += str[i] - 48;
		i++;
	}
	if (boolean && !value)
		return (0);
	if (boolean)
		value = -value;
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	return (1);
}

void	is_stack_valid(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->content_lenght)
	{
		j = i + 1;
		while (j < stack->content_lenght)
		{
			if (stack->content[i] == stack->content[j])
			{
				write(2, "Error\n", 6);
				return (free(stack->content), free(stack), exit(0));
			}
			j++;
		}
		i++;
	}
}

void	get_stack(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (argc - i < argc)
	{
		if (!is_number_valid(argv[argc - i], 0))
		{
			write(2, "Error\n", 6);
			return (free(stack->content), free(stack), exit(0));
		}
		stack->content[argc - i - 1] = ft_atoi(argv[argc - i]);
		i--;
	}
	is_stack_valid(stack);
}

int	find_small_but_big(t_stack *stack, int n, int j, int k)
{
	int	i;

	i = INT_MAX;
	while (++j < stack->content_lenght)
	{
		if (stack->content[j] < i && stack->content[j] > n)
		{
			k = j;
			i = stack->content[j];
		}
	}
	if (k == -1)
	{
		j = -1;
		while (++j < stack->content_lenght)
		{
			if (stack->content[j] < i)
			{
				k = j;
				i = stack->content[j];
			}
		}
	}
	return (k);
}
