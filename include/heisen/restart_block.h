/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Common syscall restarting data
 */
#ifndef __LINUX_RESTART_BLOCK_H
#define __LINUX_RESTART_BLOCK_H


#include <heisen/compiler.h>
#include <heisen/typing.h>
#include <heisen/types.h>

struct __kernel_timespec;
struct timespec;
struct old_timespec32;
struct pollfd;

enum timespec_type {
	TT_NONE		= 0,
	TT_NATIVE	= 1,
	TT_COMPAT	= 2,
};

/*
 * System call restart block.
 */
struct restart_block {
	unsigned long arch_data;
	long (*fn)(struct restart_block *);
	union {
		/* For futex_wait and futex_wait_requeue_pi */
		struct {
			uint32_t __user *uaddr;
			uint32_t val;
			uint32_t flags;
			uint32_t bitset;
			uint64_t time;
			uint32_t __user *uaddr2;
		} futex;
		/* For nanosleep */
		struct {
			clockid_t clockid;
			enum timespec_type type;
			union {
				struct __kernel_timespec __user *rmtp;
				struct old_timespec32 __user *compat_rmtp;
			};
			uint64_t expires;
		} nanosleep;
		/* For poll */
		struct {
			struct pollfd __user *ufds;
			int nfds;
			int has_timeout;
			unsigned long tv_sec;
			unsigned long tv_nsec;
		} poll;
	};
};

extern long do_no_restart_syscall(struct restart_block *parm);

#endif /* __LINUX_RESTART_BLOCK_H */