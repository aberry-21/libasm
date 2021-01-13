;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   ft_strlen.s                                        :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/01/13 18:48:30 by aberry            #+#    #+#             */
;*   Updated: 2021/01/13 18:48:30 by aberry           ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global				_ft_strlen

section .text

_ft_strlen:
		xor			rax, rax

.loop:	cmp			byte[rdi + rax], 0
		je			.return
		inc			rax
		jne			.loop

.return:
		ret
