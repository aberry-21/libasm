;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   ft_list_push_front.s                               :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/01/13 18:48:30 by aberry            #+#    #+#             */
;*   Updated: 2021/01/13 18:48:30 by aberry           ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global				_ft_list_push_front
extern				_ft_create_elem
section .text

_ft_list_push_front:				;rdi == begin_list, rsi == data
.create_list:						;list = ft_create_elem(data);
		push		rdi
		mov			rdi, rsi
		call		_ft_create_elem
		pop			rdi
.check:
		mov			rcx, [rdi]
		cmp			rcx, 0			;if (*begin_list)
		je			.return
		mov			[rax + 8], rcx	;list->next = *begin_list;

.return:
		mov			[rdi], rax		;*begin_list = list;
		ret