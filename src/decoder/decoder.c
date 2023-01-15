/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:20 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:28:33 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

unsigned char	*decoder(unsigned char *str, char**dict)
{
	unsigned char	*new_str;
	int				j;
	char			c[2];

	j = 0;
	new_str = NULL;
	new_str = calloc(strlen((char *)str), sizeof(char));
	while(*str)
	{
		if (strlen(dict[j]) > 0)
		{
			if(strncmp(dict[j], ((char *)str), strlen(dict[j])) == 0)
			{
				c[0] = j;
				c[1] = '\0';
				strncat((char *)new_str, c, 1);
				str += strlen(dict[j]);
				j = -1;
			}
		}
		j++;
	}
	return (new_str);
}

unsigned int	is_bit(unsigned char byte, int i)
{
	unsigned char	mask;

	mask = (1 << i);
	return byte & mask;
}

void	descompact(t_node *tree, unsigned char *str, int j)
{
	FILE			*file;
	t_node			*aux;
	unsigned char	byte;
	int				i;
	int				len;

	len = (int)strlen((char *)str);
	file = fopen("42zip.mm", "rb");
	aux = tree;
	if (file)
	{
		while (fread(&byte, sizeof(unsigned char), 1, file))
		{
			i = 7;
			while (i >= 0 && j < len)
			{
				if(is_bit(byte, i))
					aux = aux->right;
				else
					aux = aux->left;
				if (aux->left == NULL && aux->right == NULL)
				{
					printf("%c", aux->c);
					aux = tree;
					j++;
				}
				i--;
			}
		}
		fclose(file);
	}
}
