/**
********************************************************************************
*
*  Copyright (C) 2022 NEXTCHIP Inc. All rights reserved.
*
*  file    :
*
*  brief   :
*
*  author  :
*
*  date    :
*
*  version :
*
********************************************************************************
*  note    :
*
********************************************************************************
*/

#ifndef TYPE_H_
#define TYPE_H_


/*
********************************************************************************
*               TYPEDEFS
********************************************************************************
*/

typedef unsigned long long      UINT64;
typedef unsigned int            UINT32;
typedef unsigned int            ULONG;
typedef unsigned short          UINT16;
typedef unsigned short          USHORT;
typedef unsigned char           UINT8;

typedef signed long long        INT64;
typedef signed int              INT32;
typedef signed short            INT16;
typedef signed short            SHORT;
typedef signed char             INT8;

typedef char                    CHAR;
typedef float                   FLOAT;
typedef float                   FP32;
typedef unsigned char           BOOL;

/* function return value */
typedef INT32 NC_ERROR;
#define NC_TIMEOUT              (-4)    /* */
#define NC_UNINITIALIZE         (-3)    /* Function calls in the state that the block is not initialized. */
#define NC_INVALID              (-2)    /* Invalid Parameter */
#define NC_FAILURE              (-1)
#define NC_SUCCESS              (0)
#define NC_WAIT                 (1)








/*
********************************************************************************
*               LOGICAL SYMBOL TYPE
********************************************************************************
*/

#ifndef TRUE
#define TRUE                    (1U)
#endif

#ifndef FALSE
#define FALSE                   (0U)
#endif

#ifndef ON
#define ON                      (1U)
#endif

#ifndef OFF
#define	OFF                     (0U)
#endif

#ifndef ENABLE
#define ENABLE                  (1U)
#endif

#ifndef DISABLE
#define	DISABLE                 (0U)
#endif

#ifndef HIGH
#define HIGH                    (1U)
#endif

#ifndef LOW
#define	LOW                     (0U)
#endif


/* function return value */

#define NC_FAILURE              (-1)
#define NC_SUCCESS              (0)
#define NC_WAIT                 (1)


#define KB                      (1024U)
#define MB                      (1048576U)

#define KHZ                     (1000U)
#define MHZ                     (1000000U)

#define SEC                     (1U)
#define MSEC                    (1000ULL)
#define USEC                    (1000000ULL)
#define NSEC                    (1000000000U)

/* PRQA S 4600 ++ */ /* We not use standard function */
#define NULL                    (0)
/* PRQA S 4600 -- */






/*
********************************************************************************
*               MACROS
********************************************************************************
*/

#define ALIGN(x, s)                     ((x) + (s) - 1U) & ~((s) - 1U)
/* PRQA S 0303 ++ */
#define REGRW32(base_addr, offset)      *(volatile UINT32 *)((UINT32)(base_addr) + (UINT32)(offset))
/* PRQA S 0303 -- */
#define ALIGNED(x) __attribute__((aligned(x)))

#endif  /* TYPE_H_ */


/* End Of File */

