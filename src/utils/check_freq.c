/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_freq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:53:47 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:27:05 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

void	check_frequency(unsigned char *text, unsigned int freq_table[])
{
	int	i;

	i = 0;
	while(text[i])
	{
		freq_table[text[i]]++;
		i++;
	}
}
