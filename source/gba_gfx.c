#include "gba_gfx.h"


void vsync()
{
	while (REG_VCOUNT >= 160);
	while (REG_VCOUNT < 160);
}