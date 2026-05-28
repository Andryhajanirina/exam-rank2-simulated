/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:59:33 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/28 12:11:54 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	checked(char c, char *str, int index)
{
	int	i;

	if (c == '-' || c == '+')
		return (1);
	i = 0;
	while (i < index)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

// Return the size of base if is valid
int check_base(char *base)
{
	int	i;
	
	i = 0;
	while (base[i] != '\0')
	{
		if (is_space(base[i]) || checked(base[i], base, i))
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

/**
 * This function will skip all the whitespaces and signs in the string,
 * and return the final sign (1 or -1).
 * It will also update the index to point to the first character
 * of the number in the string.
 */
int	skip_whitespaces_and_signs(char *str, int *index)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*index = i;
	return (sign);
}

/**
 * This function will return the index of the character 'c' in the string 'base',
 * or -1 if 'c' is not found in 'base'.
 */
int	get_val(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}


/**
 * This function will convert the string 'str' to an integer, using the characters
 * in 'base' as the digits. It will handle optional leading whitespaces and signs.
 */
int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	i;
	int	sign;
	int	result;
	int	val;

	base_len = check_base(base);
	if (base_len == 0)
		return (0);

	sign = skip_whitespaces_and_signs(str, &i);

	result = 0;
	val = get_val(str[i], base);
	while (val != -1)
	{
		result = (result * base_len) + val;
		i++;
		val = get_val(str[i], base);
	}

	return (result * sign);
}


/* #include <stdio.h>
#include <stdlib.h>


int main(void)
{
    printf("=== Tests ft_atoi_base ===\n\n");

    // 1. Tests in base 10 (Decimal)
    printf("Base 10 - \"42\" : %d\n", ft_atoi_base("42", "0123456789"));
    printf("Base 10 - \"-42\" : %d\n", ft_atoi_base("-42", "0123456789"));
    printf("Base 10 - \"  ---++-42\" : %d\n", ft_atoi_base("  ---++-42", "0123456789"));

    // 2. Tests in base 16 (Hexadecimal)
    printf("\nBase 16 - \"2A\" (42) : %d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
    printf("Base 16 - \"-2a\" (lowercase) : %d\n", ft_atoi_base("-2a", "0123456789abcdef"));
    printf("Base 16 - \"-2a\" (lowercase) =>: %d\n", ft_atoi_base("-2A", "0123456789abcdef"));

    // 3. Tests in base 2 (Binary)
    printf("\nBase 2 - \"101010\" (42) : %d\n", ft_atoi_base("101010", "01"));

    // 4. Tests in base 8 (Octal)
    printf("\nBase 8 - \"52\" (42) : %d\n", ft_atoi_base("52", "01234567"));

    // 5. Invalid base and invalid strings
    printf("\n--- Invalid bases and strings (return 0) ---\n");
    printf("Empty base - \"42\" : %d\n", ft_atoi_base("42", ""));
    printf("Base with only one character - \"42\" : %d\n", ft_atoi_base("42", "0"));
    printf("Base with duplicates - \"42\" : %d\n", ft_atoi_base("42", "01234560"));
    printf("Base with signs - \"42\" : %d\n", ft_atoi_base("42", "012+-456789"));
    printf("Invalid character - \"Z\" (en base 10) : %d\n", ft_atoi_base("Z", "0123456789"));

    return (0);
}
 */