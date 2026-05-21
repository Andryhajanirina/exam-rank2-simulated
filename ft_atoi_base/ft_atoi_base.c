/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:45:00 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/21 13:19:54 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// 1. Vérifie si la base est valide et retourne sa longueur
// Une base est valide si : elle fait au moins 2 de taille, n'a pas de doublons, et pas de '+', '-', ou d'espaces.
int	check_base(const char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		// Vérification des caractères interdits
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' 
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		// Vérification des doublons
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2) // Une base doit avoir au moins 2 caractères (ex: "01")
		return (0);
	return (i); // Retourne la taille de la base (ex: 16 pour l'hexa)
}

// 2. Cherche la valeur numérique d'un caractère dans la base
// Exemple : si base = "0123456789abcdef", le caractère 'a' renvoie l'index 10.
int	get_val(char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1); // Retourne -1 si le caractère n'appartient pas à la base
}

// 3. La fonction principale ft_atoi_base
int	ft_atoi_base(const char *str, const char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;

	i = 0;
	sign = 1;
	result = 0;
	// Étape A : On vérifie si la base est valide
	base_len = check_base(base);
	if (base_len == 0)
		return (0);
	// Étape B : On passe les espaces/whitespaces
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	// Étape C : On gère le signe (+ ou -)
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// Étape D : Conversion tant que les caractères appartiennent à la base
	while (get_val(str[i], base) != -1)
	{
		result = result * base_len + get_val(str[i], base);
		i++;
	}
	return (result * sign);
}