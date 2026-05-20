/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_lower.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andry-ha <andry-ha@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:00:18 by andry-ha          #+#    #+#             */
/*   Updated: 2026/05/20 13:51:52 by andry-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int  is_upper(char c)
{
  return (c >= 'A' && c <= 'Z');
}

char  to_lower(char c)
{
  if (is_upper(c))
    c = (c | 32);
  return (c);
}

char    to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        c = (c & ~32);
    return (c);
}
