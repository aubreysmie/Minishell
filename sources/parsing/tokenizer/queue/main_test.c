/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:09:40 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/12 19:09:56 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "parsing.h"
#include "debug_colors.h"

void	disp_queue(t_token_queue *queue)
{
	while (queue)
	{
		printf("token content : %s%s%s\n", KCYN, queue->token.content.str, KEND);
		queue = queue->next;
	}
	printf("%send of queue%s\n\n", KRED, KEND);
}

int	main(void)
{
	t_token_queue	*queue;
	t_token_queue	*element;
	t_token			token;

	element = ft_queuenew((t_token){WORD_TOKEN, (t_lstr){"cat", 3}});
	queue = element;
	element = ft_queuenew((t_token){PIPE_TOKEN, (t_lstr){"|", 1}});
	ft_queuepush(&queue, element);
	element = ft_queuenew((t_token){WORD_TOKEN, (t_lstr){"ls", 2}});
	ft_queuepush(&queue, element);
	element = ft_queuenew((t_token){GREAT_TOKEN, (t_lstr){">", 1}});
	ft_queuepush(&queue, element);
	element = ft_queuenew((t_token){WORD_TOKEN, (t_lstr){"salade", 6}});
	ft_queuepush(&queue, element);
	element = ft_queuepop(&queue);
	token = element->token;
	free(element);
	printf("popped token : %s%s%s\n", KGRN, token.content.str, KEND);
}

// int	main(void)
// {
// 	t_token_queue	*queue;
// 	t_token_queue	*element;

// 	element = ft_queuenew((t_token){WORD_TOKEN, (t_lstr){"cat", 3}});
// 	queue = element;
// 	element = ft_queuenew((t_token){PIPE_TOKEN, (t_lstr){"|", 1}});
// 	ft_queuepush(&queue, element);
// 	element = ft_queuenew((t_token){WORD_TOKEN, (t_lstr){"ls", 2}});
// 	ft_queuepush(&queue, element);
// 	element = ft_queuenew((t_token){GREAT_TOKEN, (t_lstr){">", 1}});
// 	ft_queuepush(&queue, element);
// 	element = ft_queuenew((t_token){WORD_TOKEN, (t_lstr){"salade", 6}});
// 	ft_queuepush(&queue, element);
// 	disp_queue(queue);
// 	element = ft_queuepop(&queue);
// 	printf("popped element : %s%s%s\n", KCYN,
// 		element->token.content.str, KEND);
// 	free(element);
// 	element = ft_queuepop(&queue);
// 	printf("popped element : %s%s%s\n\n", KCYN,
// 		element->token.content.str, KEND);
// 	free(element);
// 	disp_queue(queue);
// 	ft_queuefree(queue);
// }
