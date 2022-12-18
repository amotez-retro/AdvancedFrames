//---------------------------------------------------------------------------------
// This is a small header file used to define types that are used for GBA development
// these types are named according to their signedness and their bit length
// u8 represents an unsigned integer that is 8 bits in size, this would be an unsigned
// char on 0x86 systems. 
// These are defined like this for simplicity and to keep code in appropriate spaces
//---------------------------------------------------------------------------------
#pragma once

#ifndef __GBA_TYPES_H__
#define __GBA_TYPES_H__

#include <stdint.h>
#include <stdbool.h>

//\===========================================================================================================
//\TYPEDEF our variables to indicate clearly what level of bit precision each variable has
//\===========================================================================================================
typedef uint8_t		u8;		typedef int8_t		s8;
typedef uint16_t	u16;	typedef int16_t		s16;
typedef uint32_t	u32;	typedef int32_t		s32;
//\===========================================================================================================
//\ Volatile variables
//\ The volatile key word indicates to the compiler, and the programmer. That these variables may have their values
//\ altered by an external factor, this could be a hardware switch, or some external program that can access the 
//\ memory location of the variable.
//\===========================================================================================================
typedef volatile uint8_t		v_u8;	typedef volatile int8_t			v_s8;
typedef volatile uint16_t		v_u16;	typedef volatile int16_t		v_s16;
typedef volatile uint32_t		v_u32;	typedef volatile int32_t		v_s32;

#endif //__GBA_TYPES_H__