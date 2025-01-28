/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:35 by marvin            #+#    #+#             */
/*   Updated: 2025/01/28 12:15:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./current_lib/Includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>

// Server
char	*ft_strjoin_letter(char *str, char c);
void	ft_receive(int signal);

// Client
void	send_message(pid_t pid, char c);

#endif /* MINITALK_H */