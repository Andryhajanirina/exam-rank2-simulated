/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:06:19 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/04 11:48:19 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') && (c >= 'A' && c <= 'Z'));
}

int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_lower(str[i]))
		{
			if (str[i] <= 'm')
				str[i] += 13;
			else
				str[i] -= 13;
		}
		else if (is_upper(str[i]))
		{
			if (str[i] <= 'M')
				str[i] += 13;
			else
				str[i] -= 13;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	write(1, "\n", 1);
	return (0);
}