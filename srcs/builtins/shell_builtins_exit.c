/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:06:11 by bjamin            #+#    #+#             */
/*   Updated: 2016/03/15 13:10:37 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		shell_builtins_exit_error_digit(char *param)
{
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(param, 2);
	ft_putstr_fd(": unique numeric argument required\n", 2);
}

int			shell_assert_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			shell_builtins_exit(void *sh_, t_list *environ, char **cmds)
{
	t_sh	*sh;

	sh = (t_sh *)sh_;
	UNUSED(environ);
	if (cmds[1])
	{
		if (shell_assert_digit(cmds[1]) && !cmds[2])
		{
			sh->last_res = ft_atoi(cmds[1]);
			shell_exit();
			return (ft_atoi(cmds[1]));
		}
		else
		{
			shell_builtins_exit_error_digit(cmds[1]);
			return (2);
		}
	}
	else
		shell_exit();
	return (sh->last_res);
}
