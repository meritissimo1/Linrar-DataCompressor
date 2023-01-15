/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:13:22 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:25:36 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

int	tree_height(t_node *root)
{
	int	left;
	int	right;

	if (root == NULL)
		return -1;
	else
	{
		left = tree_height(root->left) + 1;
		right = tree_height(root->right) + 1;
		if (left > right)
			return (left);
		else
			return (right);
	}	
}