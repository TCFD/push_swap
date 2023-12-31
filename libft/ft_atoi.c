/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:33:17 by rciaze            #+#    #+#             */
/*   Updated: 2023/01/24 14:41:32 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	return_value;
	int	boolean;

	i = 0;
	return_value = 0;
	boolean = 0;
	if (str[i] == '-')
	{
		boolean = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		return_value *= 10;
		return_value += str[i] - 48;
		i++;
	}
	if (boolean)
		return_value = -return_value;
	return (return_value);
}
