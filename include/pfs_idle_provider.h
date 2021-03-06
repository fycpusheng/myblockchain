/* Copyright (c) 2012, 2013, Oracle and/or its affiliates. All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

#ifndef PFS_IDLE_PROVIDER_H
#define PFS_IDLE_PROVIDER_H

/**
  @file include/pfs_idle_provider.h
  Performance schema instrumentation (declarations).
*/

#ifdef WITH_PERFSCHEMA_STORAGE_ENGINE
#ifdef MYBLOCKCHAIN_SERVER
#ifndef EMBEDDED_LIBRARY
#ifndef MYBLOCKCHAIN_DYNAMIC_PLUGIN

#include "myblockchain/psi/psi.h"

#define PSI_IDLE_CALL(M) pfs_ ## M ## _v1

C_MODE_START

PSI_idle_locker*
pfs_start_idle_wait_v1(PSI_idle_locker_state* state, const char *src_file, uint src_line);

void pfs_end_idle_wait_v1(PSI_idle_locker* locker);

C_MODE_END

#endif /* MYBLOCKCHAIN_DYNAMIC_PLUGIN */
#endif /* EMBEDDED_LIBRARY */
#endif /* MYBLOCKCHAIN_SERVER */
#endif /* WITH_PERFSCHEMA_STORAGE_ENGINE */

#endif

