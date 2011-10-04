/****************************************************************************
 *
 * /home/bat/bat/fast3202_4_0_21_3_3_1/rg/pkg/util/alloc.h
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
/* SYNC: rg/pkg/util/alloc.h <-> project/tools/util/alloc.h */

#ifndef _ALLOC_H_
#define _ALLOC_H_

#include <stdlib.h>

#include "rg_error.h"

/** Return a pointer to an allocated memory block of 'size' bytes.
 * On failure, NULL is returned and an error message is logged at
 * level 'level'.
 */
void *malloc_log(rg_error_level_t level, size_t size);

/** Return a pointer to an allocated memory block of 'size' bytes and zero
 * them. On failure, NULL is returned and an error message is logged at
 * level 'level'.
 */
void *zalloc_log(rg_error_level_t level, size_t size);

/** Change the size of the memory block pointed by 'p' to 'size' bytes. Return
 * a pointer to the newly allocated memory. On failure, NULL is returned and an
 * error message is logged at level 'level'.
 */
void *realloc_log(rg_error_level_t level, void *p, size_t size);

/** As malloc_log() with 'level' set to LERR */
static __inline__ void *malloc_l(size_t size)
{
    return malloc_log(LERR, size);
}

/** As malloc_log() with 'level' set to LEXIT (reboots the board or exits
 * the host application).
 */
static __inline__ void *malloc_e(size_t size)
{
    return malloc_log(LEXIT, size);
}

/** As zalloc_log() with 'level' set to LERR */
static __inline__ void *zalloc_l(size_t size)
{
    return zalloc_log(LERR, size);
}

/** As zalloc_log() with 'level' set to LEXIT (reboots the board or exits
 * the host application).
 */
static __inline__ void *zalloc_e(size_t size)
{
    return zalloc_log(LEXIT, size);
}

/** Return a pointer to a newly allocated memory block of 'size' bytes.
 * The memory is initialized to zero.
 */
static __inline__ void *zalloc(size_t size)
{
    /* uClibc crashes on calloc(0, 1) */
    if (!size)
	size = 4;
    return calloc(size, 1);
}

/** As realloc_log() with 'level' set to LERR */
static __inline__ void *realloc_l(void *p, size_t size)
{
    return realloc_log(LERR, p, size);
}

/** As realloc_log() with 'level' set to LEXIT (reboots the board or exits
 * the host application).
 */
static __inline__ void *realloc_e(void *p, size_t size)
{
    return realloc_log(LEXIT, p, size);
}

/** Same as free(). Used to indicate that 'p' may be NULL and that it's OK */
static __inline__ void nfree(void *p)
{
    free(p);
}

/** Free the contents of the pointer 'p' and set it to NULL */
#define ZNFREE(p) do { nfree(p); p = NULL; } while (0)

#endif

