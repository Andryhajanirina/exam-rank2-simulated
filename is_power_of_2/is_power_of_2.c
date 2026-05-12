/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:17:53 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/06 10:41:21 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

/* int	    is_power_of_2(unsigned int n)
{
    return (n > 0 && (n & -n) == n);
} */

/* int is_power_of_2(unsigned int n) {
    if (n == 0) return 0; // 0 n'est pas une puissance de 2

    while (n > 1) {
        if (n % 2 != 0) { // Si le nombre n'est pas divisible par 2
            return 0;     // Ce n'est pas une puissance de 2
        }
        n /= 2;        // On continue la division
    }
    return 1; // Si on arrive à 1, c'était une puissance de 2
} */

/* 
int main(void)
{
    int nb;

    nb = 1024;
    printf("Is power of 2 : %d", is_power_of_2(nb));
    return (0);
} */