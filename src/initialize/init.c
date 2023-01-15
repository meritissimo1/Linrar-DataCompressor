/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:27:47 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:30:48 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

void	init_list(t_list *list)
{
	list->head = NULL;
	list->size = 0;
}

void	init_table(unsigned int freq_table[])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		freq_table[i] = 0;
		i++;
	}
}
