/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:51:27 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/04 11:59:52 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

void	ulstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_lower(str[i]))
			str[i] -= 32;
		else if (is_upper(str[i]))
			str[i] += 32;
		write(1, &str[i], 1);
		i++;
	}
	
}

int	main(int argc, char **argv)
{
	if (argc ==2)
		ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}