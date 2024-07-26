/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurmus <mdurmus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:18:03 by mdurmus          #+#    #+#             */
/*   Updated: 2022/03/09 14:23:36 by mdurmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_lstsize(t_list *lst)
{
	long int		len;
	t_list			*tmp;

	len = 0;
	tmp = lst;
	if (tmp == NULL)
		return (0);
	while (tmp->next != 0)
	{
		tmp = tmp->next;
		len++;
	}
	if (tmp->next == 0)
		len++;
	return (len);
}
