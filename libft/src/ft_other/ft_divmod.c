/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:18:59 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 13:58:36 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_divmod(const int32_t dividend, const int32_t divisor,
		int32_t *remainder)
{
	*remainder = dividend % divisor;
	return (dividend / divisor);
}
