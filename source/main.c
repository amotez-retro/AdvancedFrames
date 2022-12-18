#include "Intellisense.h"
//#include "sound_player.h"
#include "bitmap.h"
#include "sound_player.h"

#include "gba_bios.h"
#include "gba_reg.h"
#include "gba_macros.h"
#include "gba_types.h"
#include "gba_gfx.h"
#include "gba_input.h"

#define img_gbaM3BitmapLen 76800

int main()
{
	playSound();
	
	//Video
	u16 vidMode = VIDEOMODE_3;
	//set GBA rendering context to MODE 3 Bitmap Rendering
	REG_DISPCNT = VIDEOMODE_3 | BGMODE_2;
	while (1) { //loop forever
		int counter = 0;
		int refreshNum = 0;
		bool paused = false;
		while (counter < numFrames) {
			PollKeys();
			if( keyReleased(A) && !paused)
				paused = true;
			else if ( keyReleased(A) && paused)
				paused = false;
			vsync();
				memcpy(SCREENBUFFER, frames[counter], img_gbaM3BitmapLen);
			if (refreshNum == 0 && !paused)
				counter++;
			refreshNum++;
			if(counter == numFrames) {
				counter = 0;
				playSound();
			} 
			if(refreshNum == 3) refreshNum = 0;
		}
	}
	
	return 0;
}