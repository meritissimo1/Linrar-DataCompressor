/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:32:59 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:28:00 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

unsigned char	*encoder(char **dict, unsigned char *text)
{
	int				i;
	int				size;
	unsigned char	*encoded;

	size = length_string(dict, text);
	encoded = calloc(size, sizeof(char));
	i = 0;
	while (text[i] != '\0')
	{
		strcat((char *)encoded, dict[text[i]]);
		i++;
	}
	return (encoded);
}

void	compact(unsigned char *encode)
{
	FILE	*file;
	int		i;
	int		j;
 	unsigned char	mask;
	unsigned char	byte;
	
	i = 0;
	byte = 0;
	j = 7;
	file = fopen("42zip.mm", "wb");
	if (file)
	{
		while (encode[i] != '\0')
		{
			mask = 1;
			if (encode[i] == '1')
			{
				mask = mask << j;
				byte = byte | mask;
			}
			j--;
			if (j < 0)
			{
				fwrite(&byte, sizeof(unsigned char), 1, file);
				byte = 0;
				j = 7;
			}
			i++;
		}
		if (j != 7)
			fwrite(&byte, sizeof(unsigned char), 1, file);
		fclose(file);
		}
	else
		printf("\nFile ERROR\n");		
}
