/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:05:47 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:27:10 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

unsigned char	*check_flags(int argc, char **str)
{
	int				size;
	unsigned char	*text;

	text = NULL;
	if (argc > 1)
	{
		if (argc == 3 && !strcmp(str[1], "-t"))
		{
			text = (unsigned char *)str[2];
			if (!strlen((char *)text))
				return (NULL);		
		}		
		else
		{
			size = 	size_file(str[1]);
			if (!size)
				return (NULL);
			text = calloc(size + 1, sizeof(unsigned char));
			read_file(text, str[1]);
		}
	}
	return (text);
}
