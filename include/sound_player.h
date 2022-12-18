#ifndef __SOUND_PLAYER_H__
#define __SOUND_PLAYER_H__

// SOUND
#include "steel.h"
/* allows turning on and off sound for the GBA altogether */
volatile unsigned short* master_sound = (volatile unsigned short*) 0x4000084;
/* has various bits for controlling the direct sound channels */
volatile unsigned short* sound_control = (volatile unsigned short*) 0x4000082;
/* the location of where sound samples are placed for each channel */
volatile unsigned char* fifo_buffer_a  = (volatile unsigned char*) 0x40000A0;
volatile unsigned char* fifo_buffer_b  = (volatile unsigned char*) 0x40000A4;
/* DMA registers */
volatile unsigned int* dma1_source = (volatile unsigned int*) 0x40000BC;
volatile unsigned int* dma1_destination = (volatile unsigned int*) 0x40000C0;
volatile unsigned int* dma1_control = (volatile unsigned int*) 0x40000C4;
/* the timer control registers */
volatile unsigned short* timer0_data = (volatile unsigned short*) 0x4000100;
volatile unsigned short* timer0_control = (volatile unsigned short*) 0x4000102;

// Definition for Gameboy Advance Register Values

/* master sound enable */
#define SOUND_MASTER_ENABLE 0x80
/* bit patterns for the sound control register */
#define SOUND_A_RIGHT_CHANNEL 0x100
#define SOUND_A_LEFT_CHANNEL 0x200
#define SOUND_A_FIFO_RESET 0x800
#define SOUND_B_RIGHT_CHANNEL 0x1000
#define SOUND_B_LEFT_CHANNEL 0x2000
#define SOUND_B_FIFO_RESET 0x8000
/* enable DMA */
#define DMA_ENABLE 0x80000000
/* this causes the DMA destination to be the same each time rather than increment */
#define DMA_DEST_FIXED 0x400000
/* this causes the DMA to repeat the transfer automatically on some interval */
#define DMA_REPEAT 0x2000000
/* transfer by word */
#define DMA_32 0x04000000
/* this causes the DMA repeat interval to be synced with timer 0 */
#define DMA_SYNC_TO_TIMER 0x30000000
/* bit positions of the timer control register */
#define TIMER_FREQ_1 0x0
#define TIMER_FREQ_64 0x2
#define TIMER_FREQ_256 0x3
#define TIMER_FREQ_1024 0x4
#define TIMER_ENABLE 0x80
//SOUND

int playSound() {
	*dma1_control = 0;
	*sound_control |= SOUND_A_RIGHT_CHANNEL | SOUND_A_LEFT_CHANNEL | SOUND_A_FIFO_RESET;
	*master_sound = SOUND_MASTER_ENABLE;
	*dma1_source = (unsigned int) steel;
	*dma1_destination = (unsigned int) fifo_buffer_a;
	*dma1_control = DMA_DEST_FIXED | DMA_REPEAT | DMA_32 | DMA_SYNC_TO_TIMER | DMA_ENABLE;
	int sample_rate = 8000;
	int CLOCK = 16777216;
	unsigned short ticks_per_sample = CLOCK / sample_rate;
	*timer0_data = 65536 - ticks_per_sample;
	*timer0_control = TIMER_ENABLE | TIMER_FREQ_1;
}

#endif