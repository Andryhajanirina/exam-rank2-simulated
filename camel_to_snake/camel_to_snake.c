/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:50:23 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/05 10:18:43 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char to_lower(char c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}

void	camel_to_snake(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isupper(str[i]))
		{
			write(1, "_", 1);
			str[i] = to_lower(str[i]);
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		camel_to_snake(argv[1]);
	write(1, "\n", 1);
	return (0);
}