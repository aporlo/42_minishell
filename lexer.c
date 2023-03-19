/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:56:01 by lsomrat           #+#    #+#             */
/*   Updated: 2023/03/17 13:56:06 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static char	*newtoken(char *str)
{
	if (ft_strncmp(str, ">", 2) == 0)
		return (ft_strdup("GREAT"));
	else if (ft_strncmp(str, "<", 2) == 0)
		return (ft_strdup("LESS"));
	else if (ft_strncmp(str, ">>", 3) == 0)
		return (ft_strdup("GREATGREAT"));
	else if (ft_strncmp(str, "<<", 3) == 0)
		return (ft_strdup("LESSLESS"));
	else if (ft_strncmp(str, "|", 2) == 0)
		return (ft_strdup("PIPE"));
	else
		return (ft_strdup(str));
}

bool	is_quote(char ch)
{
	if (ch == '"' || ch == 39)
		return (true);
	return (false);
}

char	*sub_string(char *str, int left, int right)
{
	int		i;
	char	*sub_str;

	*sub_str = (char *)malloc(sizeof(char) * (right - left + 2));
	while (i <= right)
	{
		sub_str[i - left] = str[i];
		i++;
	}
	sub_str[right - left + 1] = '\0';
	return (sub_str);
}

void	add_cmd(t_list	**cmd_ll, char *str, int right, int left, int len)
{
	char	*substr;

	substr = sub_string(str, left, right);
	ft_lstadd_back(cmd_ll, ft_lstnew(newtoken(substr)));

}

int	get_right(char *str)
{
	int		left;
	int		right;
	int		len;

	left = 0;
	right = 0;
	len = strlen(str);

	while (right < len && left <= right)
	{
		if (isspace(str[right]))
		{
			right++;
			left = right;
		}
		else if (is_quote(str[right]) == true)
		{
			quote = str[right];
			right++;
			while (str[right] != quote && right < len)
				right++;
		}
		else
		{
			right++;
			while (isspace(str[right]) == 0 && right < len)
				right++;
			{
				substr = subString(str, left, right - 1);
				ft_lstadd_back(cmd_ll, ft_lstnew(newtoken(substr)));
				left = right;
				free(substr);
			}
		}
	}

}

void	lexer(t_list **cmd_ll, char *str)
{
	// int		left;
	// int		right;
	// int		len;
	int		quote;
	char	*substr;

	// left = 0;
	// right = 0;
	// len = strlen(str);
	while (right < len && left <= right)
	{
		if (isspace(str[right]))
		{
			right++;
			left = right;
		}
		else if (is_quote(str[right]) == true)
		{
			quote = str[right];
			right++;
			while (str[right] != quote && right < len)
				right++;
			substr = sub_string(str, left, right);
			ft_lstadd_back(cmd_ll, ft_lstnew(newtoken(substr)));
			right++;
			left = right;
			free(substr);
		}
		else
		{
			right++;
			while (isspace(str[right]) == 0 && right < len)
				right++;
			{
				substr = subString(str, left, right - 1);
				ft_lstadd_back(cmd_ll, ft_lstnew(newtoken(substr)));
				left = right;
				free(substr);
			}
		}
	}
}
