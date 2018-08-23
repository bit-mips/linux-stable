/*
 * wbflush stub
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 */

#include <asm/wbflush.h>

static void wbflush_stub(void)
{
}

void (*__wbflush)(void);

void wbflush_setup(void)
{
	__wbflush = wbflush_stub;
}
