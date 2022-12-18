#pragma once

#ifndef __GBA_MACRO_H__
#define __GBA_MACRO_H__

#if __INTELLISENSE__
typedef unsigned int __SIZE_TYPE__;
typedef unsigned long __PTRDIFF_TYPE__;
#define __attribute__(q)
#define __builtin_strcmp(a,b) 0
#define __builtin_strlen(a) 0
#define __builtin_memcpy(a,b) 0
#define __builtin_va_list void*
#define __builtin_va_start(a,b)
#define __extension__
#endif

#define INLINE static inline

#define ARM __attribute__((__target__("arm")))
#define THUMB __attribute__((__target__("thumb")))

#ifndef	NULL
#define	NULL	(void*)0
#endif

#endif //__GBA_MACRO_H__
