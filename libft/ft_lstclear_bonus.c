/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:17:04 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/08 17:46:32 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (*lst == NULL || del == NULL)
		return ;
	temp = *lst;
	if (temp == NULL)
		return ;
	next = temp->next;
	while (next)
	{
		next = temp->next;
		del(temp->content);
		free(temp);
		temp = next;
	}
	free(temp);
	free(next);
	*lst = NULL;
}
