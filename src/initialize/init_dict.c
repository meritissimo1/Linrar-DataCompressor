/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:36:22 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:27:55 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

char	**init_dictionary(int columns)
{
	char	**dictionary;
	int		i;

	dictionary = malloc(sizeof(char*) * SIZE);
	i = 0;
	while (i < SIZE)
	{
		dictionary[i] = calloc(columns, sizeof(char));
		i++;
	}
	return (dictionary);
}
