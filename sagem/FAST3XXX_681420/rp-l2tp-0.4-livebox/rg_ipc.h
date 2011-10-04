/****************************************************************************
 *
 * /home/gil/dev/rg.tag/pkg/l2tp/rg_ipc.h
 * 
 * Copyright (C) Jungo LTD 2004
 * 
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General 
 * Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 *
 * Developed by Jungo LTD.
 * Residential Gateway Software Division
 * www.jungo.com
 * info@jungo.com
 */

#ifndef _RG_IPC_H_
#define _RG_IPC_H_

#include "ipc.h"

/* IPC messages between openrg and l2tpd are as follows:
 * - Openrg sends L2M_CONNECT message with params. If shared_secret_len is
 *   non-zero then the message is followed by the shared secret string.
 * - When session is established, l2tpd sends L2M_CONNECT message to main
 *   task, with the same params (but without the shared secret),
 *   Openrg uses the id field in params to identify the session.
 * - When openrg is ready, it sends L2M_ATTACH message to l2tpd with a device
 *   name throu which both process are going to pass PPP data.
 *   l2tpd uses the id field in params to identify the session and closes it.
 * - When l2tpd is up and running it sends a L2M_READY message to main task,
 *   which can now try to connect.
 */
typedef struct {
    int id; /* must be unique for each session */
    struct in_addr server_ip;
    int shared_secret_len;
} l2tpc_ipc_params_t;

typedef enum {
    L2M_CONNECT = 1,
    L2M_ATTACH = 2,
    L2M_CLOSE = 3,
    L2M_READY = 4,
} l2tpd_msg_type_t;

typedef struct {
    l2tpd_msg_type_t type;
    l2tpc_ipc_params_t params; /* used also to identify session */
} l2tpd_msg_t;

#endif

