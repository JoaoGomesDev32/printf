/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagomes <joagomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:26:14 by joagomes          #+#    #+#             */
/*   Updated: 2026/05/14 17:01:17 by joagomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINT_H

# include "libft/libft.h"
# include <stdarg.h>

va_list args;          // declara a "lista" de argumentos variádicos
/*va_start(args, fmt);   // inicializa, apontando ao último arg fixo
va_arg(args, int);     // extrai o próximo argumento (especificas o tipo!)
va_end(args); */          // limpa — SEMPRE chamar no fim

#endif PRINTF_H