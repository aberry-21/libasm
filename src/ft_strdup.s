;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   ft_strdup.s                                        :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/01/13 18:48:30 by aberry            #+#    #+#             */
;*   Updated: 2021/01/13 18:48:30 by aberry           ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global				_ft_strdup
extern				_ft_strlen
extern				_ft_strcpy
extern				_malloc

section .text

_ft_strdup:
		push		rdi
		call		_ft_strlen
		mov			rdi, rax
		inc			rdi
		call		_malloc
		pop			rsi
		test		rax, rax
		je			.return
		mov			rdi, rax
		call		_ft_strcpy

.return:
		ret