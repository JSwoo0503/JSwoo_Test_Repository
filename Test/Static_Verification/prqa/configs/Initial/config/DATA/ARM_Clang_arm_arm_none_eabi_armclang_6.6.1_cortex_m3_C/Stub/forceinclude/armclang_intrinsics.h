#ifndef __ARMCLANG_INTRINSICS_H__
#define __ARMCLANG_INTRINSICS_H__

extern void __breakpoint(int);
extern unsigned int __current_pc(void);
extern unsigned int __current_sp(void);
extern int __disable_fiq(void);
extern int __disable_irq(void);
extern void __enable_fiq(void);
extern void __enable_irq(void);
extern void __force_stores(void);
extern void __memory_changed(void);
extern void __schedule_barrier(void);
extern int __semihost(int, const void *);
extern unsigned int __vfp_status(unsigned int, unsigned int);

#endif
