;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   ft_create_elem.s                                   :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/01/13 18:48:30 by aberry            #+#    #+#             */
;*   Updated: 2021/01/13 18:48:30 by aberry           ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global				_ft_create_elem
extern				_malloc
section .text

_ft_create_elem:						;rdi == data
		push		rdi
		mov			rdi, 16
		call		_malloc				;list = malloc(16);
		pop			qword [rax]			;list->data = data;
		mov			qword [rax + 8], 0	;list->next = NULL
		ret

