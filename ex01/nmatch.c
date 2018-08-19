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

int		nmatch(char *s1, char *s2)
{
	int	count;

	if (*s2 == '\0')
		return ((*s1 == '\0') ? 1 : 0);
	if (*s2 == '*')
	{
		count = 0;
		while (*s1 != '\0')
		{
			count += nmatch(s1, (s2 + 1));
			s1++;
		}
		count += nmatch(s1, s2 + 1);
		return (count);
	}
	if (*s1 == '\0')
		return (0);
	if (*s1 == *s2)
		return (nmatch((s1 + 1), (s2 + 1)));
	else
		return (0);
}