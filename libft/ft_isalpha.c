/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurmus <mdurmus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:17:31 by mdurmus          #+#    #+#             */
/*   Updated: 2021/10/01 12:17:31 by mdurmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if ((character >= 'a' && character <= 'z')
		|| (character >= 'A' && character <= 'Z'))
		return (1);
	return (0);
}
