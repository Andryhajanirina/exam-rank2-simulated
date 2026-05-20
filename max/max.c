/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:59:54 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/06 12:04:43 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		max(int *tab, unsigned int len)
{
    int i;
    int max;

    if (tab == 0 || len ==0)
            return (0);
    i = 0;
    while (i < len)
    {
        if (tab[i] <= tab[i + 1])
            max = tab[i + 1];
        else
            max = tab[i];
        i++;
    }
    return (max);
}
