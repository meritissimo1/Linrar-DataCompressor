/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:05:53 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:26:42 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

void	read_file(unsigned char *text, char *archive)
{
	FILE	*file;
	char	c;
	int		i;

	i = 0;
	file = fopen(archive, "r");
	if (file)
	{
		while (!feof(file))
		{
			c = fgetc(file);
			if (c != -1)
				text[i] = c;
			i++;
		}
		fclose(file);
	}
	else
		printf("\nERROR read FILE\n");	
}
