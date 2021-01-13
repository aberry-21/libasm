;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   ft_strcmp.s                                        :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/01/13 18:48:30 by aberry            #+#    #+#             */
;*   Updated: 2021/01/13 18:48:30 by aberry           ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global				_ft_strcmp

section .text
_ft_strcmp:
		xor			rcx, rcx
		xor			rax, rax

.loop:
		cmp			byte[rdi + rcx], 0
		je			.return
		cmp			byte[rsi + rcx], 0
		je			.return
		mov			dl, byte[rdi + rcx]
		cmp			dl, byte[rsi + rcx]
		jne			.return
		inc			rcx
		jmp			.loop

.return:
		mov			al, byte[rdi + rcx]
		mov			dl, byte[rsi + rcx]
		sub			rax, rdx
		ret