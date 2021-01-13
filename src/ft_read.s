;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   ft_read.s                                          :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/01/13 18:48:30 by aberry            #+#    #+#             */
;*   Updated: 2021/01/13 18:48:30 by aberry           ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global				_ft_read
extern				___error

section .text

_ft_read:
		mov			rax, 0x2000003
		syscall
		jc			.error
		ret

.error:
		push		rax
		call		___error
		pop			qword[rax]
		mov			rax, -1
		ret