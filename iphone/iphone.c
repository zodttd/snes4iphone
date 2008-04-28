#include "../../../common.h"
#include "gpSPhone_iPhone.h"

u16* videobuffer;
#if 0
u8* rom_translation_cache; //[ROM_TRANSLATION_CACHE_SIZE];
u8* ram_translation_cache; //[RAM_TRANSLATION_CACHE_SIZE];
u8* bios_translation_cache; //[BIOS_TRANSLATION_CACHE_SIZE];
u8* rom_translation_ptr; // = rom_translation_cache;
u8* ram_translation_ptr; // = ram_translation_cache;
u8* bios_translation_ptr; // = bios_translation_cache;
#endif

void gp2x_deinit(void)
{
}

void gp2x_init(int bpp, int rate, int bits, int stereo, int Hz)
{
	setpriority(PRIO_PROCESS, 0, -20);
	videobuffer = (u16*)malloc(240*160*2);
#if 0
	rom_translation_cache = (u8*)malloc(ROM_TRANSLATION_CACHE_SIZE);
	ram_translation_cache = (u8*)malloc(RAM_TRANSLATION_CACHE_SIZE);
	bios_translation_cache = (u8*)malloc(BIOS_TRANSLATION_CACHE_SIZE);
	rom_translation_ptr = rom_translation_cache;
	ram_translation_ptr = ram_translation_cache;
	bios_translation_ptr = bios_translation_cache;	
#endif
}



void gp2x_quit()
{
	free(videobuffer);
#if 0
	free(rom_translation_cache);
	free(ram_translation_cache);
	free(bios_translation_cache);
#endif
}

void gp2x_sound_volume(unsigned long volume_up)
{
}

