/*
   ether.c - useful ethernet functions for systems lacking those

   Copyright (C) 2008-2017 Arthur de Jong

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301 USA
*/

#include "config.h"

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#ifdef HAVE_NETINET_ETHER_H
#include <netinet/ether.h>
#endif

#include "ether.h"

/* these functions are not really reentrant */

#ifndef HAVE_ETHER_ATON_R
struct ether_addr *ether_aton_r(const char *asc, struct ether_addr *addr)
{
  struct ether_addr *tmp;
  tmp = ether_aton(asc);
  if (tmp == NULL)
    return NULL;
  memcpy(addr, tmp, sizeof(struct ether_addr));
  return addr;
}
#endif /* not HAVE_ETHER_ATON_R */
