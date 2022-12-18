#ifndef __GBA_GFX_H__
#define __GBA_GFX_H__

#include "gba_macros.h"
#include "gba_reg.h"
#include "gba_types.h"

#define SCREENBUFFER ((u16*)(VRAM))

//base address pointer for base register
#define REG_DISPCNT *((v_u32*)(REG_BASE))

//Defines for settng up different video modes
#define VIDEOMODE_0 0x0000  //Sprite Mode 0
#define VIDEOMODE_1 0x0001  //Sprite Mode 1
#define VIDEOMODE_2 0x0002  //Sprite Mode 2
#define VIDEOMODE_3 0x0003	// < Mode 3; 240x160 @16bpp
#define VIDEOMODE_4	0x0004	// < Mode 4; 240x160 @8 bpp
#define VIDEOMODE_5 0x0005  // < Mode 5; 160x128 @16bpp

//Defines for enabling different backgrounds
#define BGMODE_0	0x0100
#define BGMODE_1	0x0200
#define BGMODE_2	0x0400
#define BGMODE_3	0x0800

//vcount is used for testing for vertical blank
#define REG_VCOUNT (*(v_u16*)(REG_BASE + 0x06))

#define MEM_TILE			((u16*)0x06000000)
#define MEM_PALETTE			((u16*)0x05000000) 


#define VIDEO_PAGE			0x0010	//!< Page indicator

#define VRAM_PAGE_SIZE		0x0A000
#define VRAM_BACK	(VRAM + VRAM_PAGE_SIZE)

#define vid_mem			((u16*)VRAM)
#define vid_page_front	((u16*)VRAM)
#define vid_page_back	((u16*)VRAM_BACK)

extern void vsync();

#endif //__GBA_GFX_H__