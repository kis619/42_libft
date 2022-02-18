/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:41:40 by kmilchev          #+#    #+#             */
/*   Updated: 2021/11/28 17:41:40 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;
// 	t_list *needed;

// 	node1 = (t_list *)malloc(sizeof(t_list));
// 	node2 = (t_list *)malloc(sizeof(t_list));
// 	node3 = (t_list *)malloc(sizeof(t_list));
// 	needed = (t_list *)malloc(sizeof(t_list));
// 	//for this to work I need to change content type to int
// 	node1->content = 1;
// 	node1->next = node2;
// 	node2->content = 2;
// 	node2->next = node3;
// 	node3->content = 453;
// 	node3->next = NULL;

// 	needed = ft_lstlast(node1);
// 	printf("%d", needed->content);
// 	return 0;
// }