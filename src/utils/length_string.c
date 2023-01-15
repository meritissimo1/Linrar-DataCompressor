/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:25:07 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:26:45 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

int	length_string(char **dict, unsigned char *cod)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (cod[i] != '\0')
	{
		size = size + strlen(dict[cod[i]]);		
		i++;
	}
	return (size + 1);
}
