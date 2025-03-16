/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_reversecase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:28:48 by plgol.perso       #+#    #+#             */
/*   Updated: 2024/05/16 09:34:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

int32_t	to_reversecase(int32_t ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	else if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	else
		return (ch);
}
