/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:46:20 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/08 21:37:28 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parsing.h"

t_token_queue	*ft_queuenew(t_token token)
{
	t_token_queue	*element;

	element = malloc(sizeof(t_token_queue));
	if (!element)
		return (NULL);
	element->token = token;
	element->next = NULL;
	return (element);
}
