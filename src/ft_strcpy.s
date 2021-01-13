;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   ft_strcpy.s                                        :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/01/13 18:48:30 by aberry            #+#    #+#             */
;*   Updated: 2021/01/13 18:48:30 by aberry           ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global				_ft_strcpy

section .text

_ft_strcpy:
		xor			rax, rax

.loop:	mov			dl, byte[rsi + rax]
		mov			byte[rdi + rax], dl
		inc			rax
		cmp			byte[rsi + rax], 0
		je			.return
		jne			.loop

.return:
		mov			rax, rdi
		ret