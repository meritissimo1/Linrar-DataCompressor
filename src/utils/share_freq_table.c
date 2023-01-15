/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_freq_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 05:13:02 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:26:28 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

void	share_freq_table(unsigned int freq_table[])
{
	unsigned int	*block;
	int				i;

	i = 0;
	block = attach_memory_block(FILENAME, SIZE);
	while (i < SIZE)
	{
		block[i] = freq_table[i];
		i++;		
	}
	detach_mem_block(block);
}
