// SPDX-License-Identifier: GPL-2.0
/*
 * stubs for systems with coherent cache
 */
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/smp.h>
#include <linux/mm.h>

#include <asm/page.h>
#include <asm/pgtable.h>
#include <asm/mmu_context.h>
#include <asm/isadep.h>
#include <asm/io.h>
#include <asm/bootinfo.h>
#include <asm/cpu.h>

static void stub_void(void)
{
}

static void stub_p(void *a)
{
}

static void stub_pll(void *a, unsigned long b, unsigned long c)
{
}

static void stub_ll(unsigned long a, unsigned long b)
{
}

static void stub_li(unsigned long a, int b)
{
}

static void stub_l(unsigned long a)
{
}

extern void coherent_cache_init(void)
{
	extern void build_clear_page(void);
	extern void build_copy_page(void);

	flush_cache_all = stub_void;
	__flush_cache_all = stub_void;
	flush_cache_mm = (void (*)(struct mm_struct *)) stub_p;
	flush_cache_range = (void (*)(struct vm_area_struct *,
				long unsigned int, long unsigned int)) stub_pll;
	flush_cache_page = (void (*)(struct vm_area_struct *,
				long unsigned int, long unsigned int)) stub_pll;
	flush_icache_range = stub_ll;
	local_flush_icache_range = stub_ll;
	__flush_icache_user_range = stub_ll;
	__local_flush_icache_user_range = stub_ll;

	__flush_kernel_vmap_range = stub_li;

	flush_cache_sigtramp = stub_l;
	local_flush_data_cache_page = stub_p;
	flush_data_cache_page = stub_l;

	build_clear_page();
	build_copy_page();
}
