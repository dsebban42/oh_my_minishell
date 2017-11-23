/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:51:13 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/28 18:24:34 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ERRNO_H
# define MY_ERRNO_H

# define EPERM				1
# define ENOENT				2
# define ESRCH 	 			3
# define EINTR 	 			4
# define EIO 				5
# define E2BIG 	 			7
# define ENOEXEC			8
# define EBADF 	 			9
# define ECHILD 			10
# define EAGAIN 			11
# define ENOMEM				12
# define EACCES 			13
# define EFAULT 			14
# define ENOTBLK			15
# define EBUSY				16
# define EEXIST 			17
# define EXDEV				18
# define ENODEV 			19
# define ENOTDIR			20
# define EISDIR 			21
# define EINVAL 			22
# define ENFILE 			23
# define EMFILE 			24
# define ENOTTY 			25
# define ETXTBSY			26
# define EFBIG				27
# define ENOSPC 			28
# define ESPIPE 			29
# define EROFS				30
# define EMLINK 			31
# define EPIPE				32
# define EDOM				33
# define ERANGE 			34
# define EDEADLK	 		35
# define ENAMETOOLONG		36
# define ENOLCK				37
# define ENOSYS				38
# define ENOTEMPTY	 		39
# define ELOOP	 			40
# define ENOMSG				41
# define EIDRM				42
# define ECHRNG				43
# define EL2NSYNC			44
# define EL3HLT				45
# define EL3RST				46
# define ELNRNG				47
# define EUNATCH	 		48
# define ENOCSI				49
# define EL2HLT				50
# define EBADE				51
# define EBADR				52
# define EXFULL				53
# define ENOANO				54
# define EBADSLT	 		55
# define EBFONT				57
# define ENOSTR				58
# define ENODATA		 	59
# define ETIME				60
# define ENOSR				61
# define ENONET				62
# define ENOPKG				63
# define EREMOTE			64
# define ENOLINK			65
# define EADV	 			66
# define ESRMNT				67
# define ECOMM				68
# define EPROTO				69
# define EMULTIHOP			70
# define EDOTDOT		 	71
# define EBADMSG			72
# define EOVERFLOW			73
# define ENOTUNIQ			74
# define EBADFD				75
# define EREMCHG			76
# define ELIBACC			77
# define ELIBBAD			78
# define ELIBSCN			79
# define ELIBMAX			80
# define ELIBEXEC			81
# define EILSEQ				82
# define ERESTART			83
# define ESTRPIPE			84
# define EUSERS				85
# define ENOTSOCK			86
# define EDESTADDRREQ		87
# define EMSGSIZE			88
# define EPROTOTYPE			89
# define ENOPROTOOPT		90
# define EPROTONOSUPPORT	91
# define ESOCKTNOSUPPORT	92
# define EOPNOTSUPP			93
# define EPFNOSUPPORT		94
# define EAFNOSUPPORT		95
# define EADDRINUSE 		96
# define EADDRNOTAVAIL		97
# define ENETDOWN			98
# define ENETUNREACH		99
# define ENETRESET			100
# define ECONNABORTED		101
# define ECONNRESET			102
# define ENOBUFS			103
# define EISCONN			104
# define ENOTCONN			105
# define ESHUTDOWN			106
# define ETOOMANYREFS		107
# define ETIMEDOUT			108
# define ECONNREFUSED		109
# define EHOSTDOWN			110
# define EHOSTUNREACH		111
# define EALREADY			112
# define EINPROGRESS		113
# define ESTALE				114
# define EUCLEAN			115
# define ENOTNAM	 		116
# define ENAVAIL			117
# define EISNAM				118
# define EREMOTEIO			119
# define EDQUOT				120
# define ENOMEDIUM			121
# define EMEDIUMTYPE		122
# define ECANCELED			123
# define ENOKEY				124
# define EKEYEXPIRED		125
# define EKEYREVOKED		126
# define EKEYREJECTED		127
# define EOWNERDEAD			128
# define ENOTRECOVERABLE 	129

void			error_call(int err_type);
const char		*return_error(int err_type);

#endif
