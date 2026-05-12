/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:38:52 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/05 15:26:08 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_space(char c)
{
	return ((c == 9 && c <= 13) || c == 32);
}

void	str_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_upper(str[i]))
			str[i] += 32;
		if (is_lower(str[i]) && (i == 0 || is_space(str[i - 1])))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
	
}

int	main(int argc, char **argv)
{
	int	i;
	
	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	
	return (0);
}
