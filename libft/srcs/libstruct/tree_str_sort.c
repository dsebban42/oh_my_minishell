/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_str_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:18:05 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:54:38 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	tree_str_sort(t_tree **tree, char *str)
{
	t_tree *temp;

	temp = NULL;
	if (!(*tree))
	{
		if (!(temp = (t_tree *)malloc(sizeof(t_tree))))
			print_err("Malloc Error: tree_create");
		temp->left = NULL;
		temp->right = NULL;
		temp->data = ft_strdup(str);
		*tree = temp;
		return ;
	}
	if (ft_strcmp(str, (*tree)->data) < 0)
		tree_str_sort(&(*tree)->left, str);
	else if (ft_strcmp(str, (*tree)->data) > 0)
		tree_str_sort(&(*tree)->right, str);
}
