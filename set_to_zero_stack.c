/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_to_zero_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:15:38 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/04 16:55:27 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_to_zero_stack(t_stack *b)
{
	int	i;

	i = b->used_size - 1;
	while (i >= 0)
	{
		b->arr[i].val = 0;
		b->arr[i].index = -1;
		i--;
	}
	b->used_size = 0;
}
