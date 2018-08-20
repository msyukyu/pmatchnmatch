/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:05:31 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 14:22:21 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		nmatch(char *s1, char *s2)
{
	int	count;

	if (*s2 == '\0')
		return (*s1 == '\0');
	if (*s1 == '\0')
		return ((*s2 == '*') ? nmatch(s1, (s2 + 1)) : 0);	
	if (*s2 == '*')
		return (nmatch(s1, (s2 + 1)) + nmatch((s1 + 1), s2));
	if (*s1 == *s2)
		return (nmatch((s1 + 1), (s2 + 1)));
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d", nmatch(argv[1], argv[2]));
	}
	return (0);
}
