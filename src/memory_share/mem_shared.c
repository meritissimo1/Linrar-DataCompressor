/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_shared.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:16:03 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:27:35 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

 static int	get_shared_block(char *filename, int size)
 {
	key_t key;

	key = ftok(filename, 0);
	if (key == IPC_RESULT_ERROR)
		return (IPC_RESULT_ERROR);
	return (shmget(key, size, 0644 | IPC_CREAT));
 }

unsigned int	*attach_memory_block(char *filename, int size)
{
	int 			block_id;
	unsigned int	*result;

	block_id = get_shared_block(filename, size);
	if (block_id == IPC_RESULT_ERROR)
		return (NULL);
	result = shmat(block_id, NULL, 0);
	if (result == (unsigned int *)IPC_RESULT_ERROR)
		return (NULL);
	return (result);
}

unsigned char	*attach_memory_text(char *filename, int size)
{
	int				block_id;
	unsigned char	*result;

	block_id = get_shared_block(filename, size);
	if (block_id == IPC_RESULT_ERROR)
		return (NULL);
	result = shmat(block_id, NULL, 0);
	if (result == (unsigned char *)IPC_RESULT_ERROR)
		return (NULL);
	return (result);
}

bool	detach_mem_block(unsigned int *block)
{
	return (shmdt(block) != IPC_RESULT_ERROR);
}

bool	destroy_mem_block(char *filename)
{
	int	block_id = get_shared_block(filename, 0);

	if (block_id == IPC_RESULT_ERROR)
		return (NULL);
	return (shmctl(block_id, IPC_RMID, NULL) != IPC_RESULT_ERROR);
}
