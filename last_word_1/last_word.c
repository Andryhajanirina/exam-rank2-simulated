/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:37:58 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/06 11:58:43 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_space(char c)
{
	return (c == 9 || c == 32);
}

void	last_word(char *str)
{
	int	i;
    int end;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0 && is_space(str[i]))
		i--;
	end = i;
	while (i >= 0 && !is_space(str[i]))
		i--;
	i++;
	while (i <= end)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}