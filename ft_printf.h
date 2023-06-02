/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:27:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/06/02 17:34:41 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

// =========================== CHAR AND STR ================================= //

int	type_c(char c, int *i);
int	type_s(char *c, int *i);

// =========================== PTRS AND NUM ================================= //

int	type_di(int n, int *i);
int	type_p(unsigned long n, int *i);
int	type_u_xlow_xup(unsigned int n, int *i, int opt, unsigned int bas);

// =========================== MAIN FUNTIONS ================================ //

int	ft_printf(char const *str, ...);

/* Update new fd_printf */
// =========================== CHAR AND STR ================================= //

int	fd_type_c(int fd, char c, int *i);
int	fd_type_s(int fd, char *c, int *i);

// =========================== PTRS AND NUM ================================= //

int	fd_type_di(int fd, int n, int *i);
int	fd_type_p(int fd, unsigned long n, int *i);
int	fd_type_u(int fd, unsigned int n, int *i);
int	fd_type_x(int fd, unsigned int n, int *i);
int	fd_type_xup(int fd, unsigned int n, int *i);

// =========================== MAIN FUNTIONS ================================ //

int	fd_printf(int fd, char const *str, ...);

#endif
