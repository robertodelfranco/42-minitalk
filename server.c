/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:37 by marvin            #+#    #+#             */
/*   Updated: 2025/01/28 12:15:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin_letter(char *str, char c)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = (char *)malloc(ft_strlen(str) + 2);
	if (!new_str)
		return (NULL);
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j++] = c;
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

void	ft_receive(int signal)
{
	static char	c = 0;
	static char	*str;
	static int	bit_count = 0;

	if (!str)
		str = ft_strdup("");
	if (signal == SIGUSR2)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		str = ft_strjoin_letter(str, c);
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;

	printf("Server PID: %d\n", getpid());
	signal.sa_handler = ft_receive;
	signal.sa_flags = 0;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		usleep(1000);
	return (0);
}
