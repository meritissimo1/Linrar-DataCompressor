/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 06:28:56 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:26:22 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

bool	detach_mem_text(unsigned char *block)
{
	return (shmdt(block) != IPC_RESULT_ERROR);
}

void	share_text(unsigned char *str)
{
	unsigned char	*block;
	int				i;

	i = 0;
	block = attach_memory_text(FILENAME, BLOCK_SIZE);
	while (i < SIZE)
	{
		block[i] = str[i];
		i++;		
	}
	detach_mem_text(block);
}
