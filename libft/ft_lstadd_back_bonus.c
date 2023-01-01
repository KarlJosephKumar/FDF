/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:50:52 by kakumar           #+#    #+#             */
/*   Updated: 2022/11/08 17:01:41 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_list;	

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp_list = *lst;
	while (temp_list->next != NULL)
		temp_list = temp_list->next;
	temp_list->next = new;
}
