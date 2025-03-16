/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:08:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 15:08:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_trim_left(char *source, uint64_t amount)
{
	uint64_t	slen;

	if (!source)
		return (NULL);
	slen = string_length(source);
	if (amount >= slen)
		return (string_clone(""));
	return (string_clone((void *)&source[amount]));
}

char	*string_trim_right(char *source, uint64_t amount)
{
	uint64_t	slen;
	char		*ret;

	if (!source)
		return (NULL);
	slen = string_length(source);
	if (amount >= slen)
		return (string_clone(""));
	ret = alloc(slen - amount + 1);
	if (!ret)
		return (NULL);
	string_copy_until_scalar(ret, source, '\0', slen - amount + 1);
	ret[slen - amount] = '\0';
	return (ret);
}

char	*string_trim_both(char *source, uint64_t amount)
{
	uint64_t	trim_both_amount;
	uint64_t	slen;
	char		*ret;

	if (!source)
		return (NULL);
	slen = string_length(source);
	if (amount >= slen)
		return (string_clone(""));
	trim_both_amount = amount * 2;
	if (trim_both_amount >= slen)
		return (string_clone(""));
	ret = alloc(slen - trim_both_amount + 1);
	if (!ret)
		return (NULL);
	string_copy_until_scalar(ret, &source[amount], '\0', slen - trim_both_amount
		+ 1);
	ret[slen - trim_both_amount] = '\0';
	return (ret);
}
