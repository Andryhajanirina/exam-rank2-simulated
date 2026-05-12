/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:51:46 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/05 13:18:37 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
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
	while (i >= 0 && ft_isspace(str[i]))
		i--;
	end = i;
	while (i >= 0 && !ft_isspace(str[i]))
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