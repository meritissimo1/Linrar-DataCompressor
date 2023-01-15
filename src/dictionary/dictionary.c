/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:42:11 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:28:25 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

void	creat_dict(char **dict, t_node *root, char *bits, int columns)
{
	char	left[columns];
	char	right[columns];

	if (root->left == NULL && root->right == NULL)
		strcpy(dict[root->c], bits);
	else
	{
		strcpy(left, bits);
		strcpy(right, bits);
		strcat(left, "0");
		strcat(right, "1");
		creat_dict(dict, root->left, left, columns);
		creat_dict(dict, root->right, right, columns);
	}		
}
