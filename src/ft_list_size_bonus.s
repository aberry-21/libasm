;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   ft_list_size.s                                     :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/01/13 18:48:30 by aberry            #+#    #+#             */
;*   Updated: 2021/01/13 18:48:30 by aberry           ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global				_ft_list_size

section .text

_ft_list_size:						;rdi == begin_list
		xor			rax, rax		;i = 0
		mov			rsi, rdi		;t_list	*list = begin_list

.loop:	test		rsi, rsi		; if list == NULL
		je			.return			; then return
		inc			rax				; i++
		mov			rsi, [rsi + 8]	; list = list->next
		jmp			.loop			; while(list)

.return:
		ret
