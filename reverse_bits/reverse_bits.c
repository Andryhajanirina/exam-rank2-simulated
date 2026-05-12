/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:02:14 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/06 11:08:02 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	bits;
	unsigned char reverse_bits;

	bits = 8;
	reverse_bits = 0;
	while (bits)
	{
		reverse_bits = (reverse_bits << 1) | (octet & 1);
		octet >>= 1;
		bits--;
	}
	return (reverse_bits);
}