
#ifndef __GBA_BIOS_H__
#define __GBA_BIOS_H__

#include "gba_reg.h"
#include "gba_macros.h"
#include "gba_types.h"

typedef void (*fnptr)(void);

//define some interrupt registers
//master interrupt controller 0 off 1 on
#define REG_IME (*(v_u16*)(0x4000208))
//Interrupts that are registered or Interrupts Expected
#define REG_IE (*(v_u16*)(0x4000200))
//IF is the interrupt Fired, 
#define REG_IF (*(v_u16*)(0x4000202))
//REG_INTERRUPT this memory address is where the interrupt funciton pointer will be stored
#define REG_INTERRUPT *(fnptr*)(0x03007FFC)
//REG_DIPSTAT interrupts for the display need to be registered here too
// for the display to fire the interrupts off
#define REG_DISPSTAT (*(v_u16*)(0x4000004))
//REG_IFBIOS this is the BIOS register address that needs to be set to inform the bios 
//that any interrupts it was expecting have been dealt with.
#define REG_IFBIOS (*(v_u16*)(0x3007FF8))
//Defines for Interrupts
//There are 14 Interrupts that we can register with REG_IE
#define INT_VBLANK 	0x0001
#define INT_HBLANK 	0x0002
#define INT_VCOUNT 	0x0004
#define INT_TIMER0 	0x0008
#define INT_TIMER1 	0x0010
#define INT_TIMER2 	0x0020
#define INT_TIMER3 	0x0040
#define INT_COM 	0x0080
#define INT_DMA0 	0x0100
#define INT_DMA1	0x0200
#define INT_DMA2 	0x0400
#define INT_DMA3 	0x0800
#define INT_BUTTON 	0x1000
#define INT_CART 	0x2000
//create pointer to video memory
#define DSTAT_VBL_IRQ 0x0008
#define DSTAT_VHB_IRQ 0x0010
#define DSTAT_VCT_IRQ 0x0020


void vblank_intr_wait();
ARM void interruptHandler();
void register_vblank_isr();

#endif //__GBA_BIOS_H__