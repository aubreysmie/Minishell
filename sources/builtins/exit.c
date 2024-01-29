/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:24:05 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/29 10:43:09 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "session.h"
#include "utils.h"
#include "errors.h"
#include "execution.h"

static bool	is_sup_to(char *num1, char *num2)
{
	if (ft_strlen(num1) > ft_strlen(num2))
		return (true);
	if (ft_strlen(num1) < ft_strlen(num2))
		return (false);
	return (ft_strcmp(num1, num2) > 0);
}

static void	exit_without_arg(int len, char **argv, t_session *session)
{
	if (len == 1)
		destroy_and_exit(0, session);
	if (!ft_strisnum(argv[1]) || is_sup_to(argv[1], "9223372036854775807"))
		disp_access_error(argv[0], argv[1], "numeric argument required");
	else
		disp_access_error(argv[0], NULL, "too many arguments");
	destroy_and_exit(2, session);
}

void	ft_exit(char **argv, t_session *session)
{
	int	len;

	len = ft_stralen(argv);
	write(2, "exit\n", 5);
	if (len != 2)
		exit_without_arg(len, argv, session);
	if (!ft_strisnum(argv[1]) || is_sup_to(argv[1], "9223372036854775807"))
	{
		disp_access_error(argv[0], argv[1], "numeric argument required");
		destroy_and_exit(2, session);
	}
	if (is_sup_to(argv[1], "255"))
		destroy_and_exit(255, session);
	destroy_and_exit(ft_atoui(argv[1]), session);
}
