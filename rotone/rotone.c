/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:14:32 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/04 10:31:30 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_alpha_without_z(char c)
{
    return ((c >= 'A' && c <= 'Y') || (c >= 'a' && c <= 'y'));
}

void	rotone(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (is_alpha_without_z(str[i]))
			str[i] += 1;
		else if(str[i] == 'Z' || str[i] == 'z')
			str[i] -= 25;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}