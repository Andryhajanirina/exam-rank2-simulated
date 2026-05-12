/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:33:24 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/05 15:54:33 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return ((c == 9 && c <= 13) || c == 32);
}

void	epur_str(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (is_space(str[i]))
			flag = 1;
		if (!is_space(str[i]))
		{
			if (flag == 1)
				write(1, " ", 1);
			flag = 0;
			write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}