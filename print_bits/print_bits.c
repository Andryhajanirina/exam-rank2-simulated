/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:40:47 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/05 09:50:00 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_bits(unsigned char octet)
{
    int bits;
    
    bits = 7;
    while (bits >= 0)
    {
        if ((octet >> bits) & 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        bits--;
    }
}