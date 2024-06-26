#ifndef __ARM_MPU_H
#define __ARM_MPU_H

#include <heisen/typing.h>

/* MPUIR layout */
#define MPUIR_nU		1
#define MPUIR_DREGION		8
#define MPUIR_IREGION		16
#define MPUIR_DREGION_SZMASK	(0xFF << MPUIR_DREGION)
#define MPUIR_IREGION_SZMASK	(0xFF << MPUIR_IREGION)

/* ID_MMFR0 data relevant to MPU */
#define MMFR0_PMSA		(0xF << 4)
#define MMFR0_PMSAv7		(3 << 4)
#define MMFR0_PMSAv8		(4 << 4)

/* MPU D/I Size Register fields */
#define PMSAv7_RSR_SZ		1
#define PMSAv7_RSR_EN		0
#define PMSAv7_RSR_SD		8

/* Number of subregions (SD) */
#define PMSAv7_NR_SUBREGS	8
#define PMSAv7_MIN_SUBREG_SIZE	256

/* The D/I RSR value for an enabled region spanning the whole of memory */
#define PMSAv7_RSR_ALL_MEM	63

/* Individual bits in the DR/IR ACR */
#define PMSAv7_ACR_XN		(1 << 12)
#define PMSAv7_ACR_SHARED	(1 << 2)

/* C, B and TEX[2:0] bits only have semantic meanings when grouped */
#define PMSAv7_RGN_CACHEABLE		0xB
#define PMSAv7_RGN_SHARED_CACHEABLE	(PMSAv7_RGN_CACHEABLE | PMSAv7_ACR_SHARED)
#define PMSAv7_RGN_STRONGLY_ORDERED	0

/* Main region should only be shared for SMP */
#ifdef CONFIG_SMP
#define PMSAv7_RGN_NORMAL	(PMSAv7_RGN_CACHEABLE | PMSAv7_ACR_SHARED)
#else
#define PMSAv7_RGN_NORMAL	PMSAv7_RGN_CACHEABLE
#endif /*CONFIG_SMP*/

/* Access permission bits of ACR (only define those that we use)*/
#define PMSAv7_AP_PL1RO_PL0NA	(0x5 << 8)
#define PMSAv7_AP_PL1RW_PL0RW	(0x3 << 8)
#define PMSAv7_AP_PL1RW_PL0R0	(0x2 << 8)
#define PMSAv7_AP_PL1RW_PL0NA	(0x1 << 8)

#define PMSAv8_BAR_XN		1

#define PMSAv8_LAR_EN		1
#define PMSAv8_LAR_IDX(n)	(((n) & 0x7) << 1)


#define PMSAv8_AP_PL1RW_PL0NA	(0 << 1)
#define PMSAv8_AP_PL1RW_PL0RW	(1 << 1)
#define PMSAv8_AP_PL1RO_PL0RO	(3 << 1)

#ifdef CONFIG_SMP
#define PMSAv8_RGN_SHARED	(3 << 3) // inner sharable
#else
#define PMSAv8_RGN_SHARED	(0 << 3)
#endif /*CONFIG_SMP*/

#define PMSAv8_RGN_DEVICE_nGnRnE	0
#define PMSAv8_RGN_NORMAL		1

#define PMSAv8_MAIR(attr, mt)	((attr) << ((mt) * 8))

#ifdef CONFIG_CPU_V7M
#define PMSAv8_MINALIGN		32
#else
#define PMSAv8_MINALIGN		64
#endif /*CONFIG_CPU_V7M*/

/* For minimal static MPU region configurations */
#define PMSAv7_PROBE_REGION	0
#define PMSAv7_BG_REGION	1
#define PMSAv7_RAM_REGION	2
#define PMSAv7_ROM_REGION	3

/* Fixed for PMSAv8 only */
#define PMSAv8_XIP_REGION	0
#define PMSAv8_KERNEL_REGION	1

/* Maximum number of regions Linux is interested in */
#define MPU_MAX_REGIONS	16

#define PMSAv7_DATA_SIDE	0
#define PMSAv7_INSTR_SIDE	1

#ifndef __ASSEMBLY__

struct mpu_rgn {
	/* Assume same attributes for d/i-side  */
	union {
		uint32_t drbar;   /* PMSAv7 */
		uint32_t prbar;   /* PMSAv8 */
	};
	union {
		uint32_t drsr;   /* PMSAv7 */
		uint32_t prlar;  /* PMSAv8 */
	};
	union {
		uint32_t dracr;  /* PMSAv7 */
		uint32_t unused; /* not used in PMSAv8 */
	};
};

struct mpu_rgn_info {
	unsigned int used;
	struct mpu_rgn rgns[MPU_MAX_REGIONS];
};
extern struct mpu_rgn_info mpu_rgn_info;

#ifdef CONFIG_ARM_MPU
extern void __init pmsav7_adjust_lowmem_bounds(void);
extern void __init pmsav8_adjust_lowmem_bounds(void);

extern void __init pmsav7_setup(void);
extern void __init pmsav8_setup(void);
#else
static inline void pmsav7_adjust_lowmem_bounds(void) {};
static inline void pmsav8_adjust_lowmem_bounds(void) {};
static inline void pmsav7_setup(void) {};
static inline void pmsav8_setup(void) {};
#endif /*CONFIG_ARM_MPU*/

#endif /* __ASSEMBLY__ */

#endif /*__ARM_MPU_H*/