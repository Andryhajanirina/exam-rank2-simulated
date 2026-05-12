/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:09:30 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/05 14:35:01 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	to_upper(char c)
{
	if (is_lower(c))
		c -= 32;
	return (c);
}

void	snake_to_camel(char *str)
{
	int	i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '_')
		{
			i++;
			c = to_upper(str[i]);
			write(1, &c, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc ==2)
		snake_to_camel(argv[1]);
	write(1, "\n", 1);
	return (0);
}