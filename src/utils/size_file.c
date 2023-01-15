/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:55:34 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:26:16 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

int	size_file(char *archive)
{
	FILE	*file;
	int		size;

	size = 0;
	file = fopen(archive, "r");
	if (file)
	{
		while(fgetc(file) != -1)
			size++;
	}
	else
	{
		if (archive[0] == '-')
			printf("Flag '%s' invalid\n", archive);
		else
			printf("File '%s' doesn't exist\n", archive);
	}		
	return (size);
}
