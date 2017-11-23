/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 11:56:17 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/28 14:56:19 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errno.h"
#include "libft.h"

static const char	*tab1(int err_type)
{
	static const char *lst_error[] = {
	"Operation not permitted", "No such file or directory",
	"No such process", "Interrupted system call", "I/O error", "No such device",
	"Argument list too long", "Exec format error", "Bad file number",
	"No child process", "Try again", "Out of memory", "Permission denied",
	"Bad address", "Block device required", "Device or ressource busy",
	"File exists", "Cross-device link", "No such device", "Not a directory",
	"Is a directory", "Invalid argument", "File table overflow",
	"Too many open files", "Not a typewriter", "Text file busy",
	"File too large", "No space left on device", "Illegal seek",
	"Read-only file system", "Too many links", "Broken pipe",
	"Math argumen out of domain of funct", "Math result not representable",
	"Resource deadlock would occur", "File name too long"};

	return (lst_error[err_type - 1]);
}

static const char	*tab2(int err_type)
{
	static const char *lst_error[] = {
	"No record locks available", "Function not implemented",
	"Directory not empty", "Too many symbolic links encountered",
	"No message of desired type", "Identifier removed",
	"Channel number out of range", "Level 2 not synchronized", "Level 3 halted",
	"Level 3 reset", "Link number out of range", "Protocol driver not attached",
	"No CSI struct available", "Level 2 halted", "Invalid exchange",
	"Invalid request descriptor", "Exchange full", "No anode",
	"Invalid request code", "Invalid slot", "Bad font file format",
	"Device not a stream", "No data aviable", "Timer expired",
	"Out of streams resources", "Mahine is not on the network",
	"Pakage not installed", "Object is remote", "Link has been severed",
	"Advertise error", "Srmount error", "Communication error on send",
	"Protocol error", "Multihop attempted", "RFS specific error",
	"Not a data message", "Value too large for defined data type",
	"Name not unique on network", "File descriptor in bad state",
	"Remote address changed", "Can not access a needed shared library",
	"Accessing a corrupted shared library"};

	return (lst_error[err_type - 1]);
}

static const char	*tab3(int err_type)
{
	static const char *lst_error[] = {
	".lib section in a.out corrupted",
	"Attempting to link in too many shared libraries",
	"Cannot exec a shared library directly", "Illegal byte sequence",
	"Interrupted system call should be restarted", "Streams pipe error",
	"Too many users", "Socket operation on non-socket",
	"Destination address required", "Message too long",
	"Protocol wrong type for socket", "Protocol not available",
	"Protocol not supported", "Socket type not supported",
	"Operation not supported on transport endpoint",
	"Protocol family not supported",
	"Address family not supported by protocol", "Address already in use",
	"Cannot assign requested address", "Network is down",
	"Network is unreachable",
	"Network dropped connection because of reset"};

	return (lst_error[err_type - 1]);
}

static const char	*tab4(int err_type)
{
	static const char *lst_error[] = {
	"Software caused connection abort",
	"Connection reset by peer",
	"No buffer space available", "Tansport endpoint is already connected",
	"Transport endpoint is not connected",
	"Cannot send after transport endpoint shutdown",
	"Too many references: cannot splice", "Connection timed out",
	"Connection refused", "Host is down", "No route to host",
	"Operation already in progress", "Operation now in progress",
	"Stale NFS file handle", "Structure needs cleaning",
	"Not a XENIX named type file", "No XENIX semaphores available",
	"Is a named type file", "Remote I/O error", "Quota exceeded",
	"No medium found", "Wrong medium type", "Operation Canceled",
	"Required key not available", "Key has expired", "Key has been revoked",
	"Key was rejected by service", "Owner died", "State not recoverable"};

	return (lst_error[err_type - 1]);
}

const char			*return_error(int err_type)
{
	if (err_type < 37)
		return (tab1(err_type));
	else if (err_type > 36 && err_type < 79)
		return (tab2(err_type - 36));
	else if (err_type > 78 && err_type < 101)
		return (tab3(err_type - 78));
	else if (err_type > 100 && err_type < 130)
		return (tab4(err_type - 100));
	return (NULL);
}
