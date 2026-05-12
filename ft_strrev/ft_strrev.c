/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:19:57 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/05 11:04:31 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *ft_strrev(char *str)
{
    int length;
    char tmp;
    int i;

    length = 0;
    i = 0;
    while (str[length])
        length++;
    while (i < length / 2)
    {
        tmp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = tmp;
        i++;
    }
    return (str);
}

#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc == 2)
        printf("%s", ft_strrev(argv[1]));
    write(1, "\n", 1);
    return (0);
}