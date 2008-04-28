VERSION=1.5.0
COPT = -march=armv6k -maspen-version-min=1.0 -g -I . -O3 -DVERSION='"$(VERSION)"' -D__IPHONE__ -D_SNESPPC -DSPC700_C -DCPU_SHUTDOWN -DSPC700_SHUTDOWN -DZLIB -DVAR_CYCLES -DUNZIP_SUPPORT -DOLD_COLOUR_BLENDING -DUSE_SA1 -DSUPER_FX 
COPT += -ffast-math -fexpensive-optimizations -finline -finline-functions -falign-functions=32 -falign-loops -falign-labels -falign-jumps -fomit-frame-pointer
GCC = /usr/local/bin/arm-apple-darwin8-gcc
GXX = /usr/local/bin/arm-apple-darwin8-g++
STRIP = /usr/local/bin/arm-apple-darwin8-strip
ADSASM = /usr/local/bin/arm-apple-darwin8-as
#-DSPC700_SHUTDOWN
#-DRC_OPTIMIZED 
# SNES stuff (c-based)
#
OBJS = apu.o c4.o c4emu.o cheats.o cheats2.o clip.o cpu.o cpuops.o cpuexec.o data.o 
OBJS += dma.o dsp1.o fxemu.o fxinst.o gfx.o globals.o input.o ioapi.o loadzip.o memmap.o menu.o ppu.o  
OBJS += sa1.o sa1cpu.o sdd1.o sdd1emu.o snapshot.o soundux.o spc700.o srtc.o tile.o unzip.o
#
# ASM CPU Core, ripped from Yoyo's OpenSnes9X
#
#OBJS += os9x_65c816.o 
# os9x_asm_cpu.o spc700a.o
#
# and some asm from LJP...
#
# OBJS += m3d_func.o
#
# Dave's minimal SDK
#
OBJS += iphone_sdk.o iphone_menutile.o iphone_highlightbar.o iphone_menu_header.o
OBJS += iphone/main.o iphone/app.o iphone/ControllerView.o iphone/MainView.o iphone/FileTable.o iphone/FileBrowser.o iphone/EmulationView.o iphone/ScreenView.o iphone/app_iPhone.o  iphone/JoyPad.o 


#
# and the glue code that sticks it all together :)
#
OBJS += main.o

# Inopia's menu system, hacked for the GP2X under rlyeh's sdk
PRELIBS = -lobjc \
            -framework CoreFoundation \
            -framework Foundation \
            -framework UIKit \
            -framework LayerKit \
            -framework CoreGraphics \
            -framework GraphicsServices \
            -framework CoreSurface \
            -framework CoreAudio \
            -framework Celestial \
            -framework AudioToolbox \
            -lz

all: pocketsnes
clean: tidy

.c.o:
	$(GCC) $(COPT) -c $< -o $@

.cpp.o:
	$(GXX) $(COPT) -c $< -o $@

%.o: %.m
	$(GCC) ${COPT} -c $< -o $@
	
# make seems to lowercase the extensions, so files with '.S' end up being passed to the compiler as '.s', which means thousands of errors.
# this is a small workaround. 

spc700a.o: spc700a.s
	$(GCC) $(COPT) -c $< -o $@

os9x_65c816.o: os9x_65c816.s
	$(GCC) $(COPT) -c $< -o $@

osnes9xgp_asmfunc.o: osnes9xgp_asmfunc.s
	$(GCC) $(COPT) -c $< -o $@

m3d_func.o: m3d_func.S
	$(GCC) $(COPT) -c $< -o $@

spc_decode.o: spc_decode.s
	$(GCC) $(COPT) -c $< -o $@

memset.o: memset.s
	$(GCC) $(COPT) -c $< -o $@

memcpy.o: memcpy.s
	$(GCC) $(COPT) -c $< -o $@

dspMixer.o: dspMixer.s
	$(GCC) $(COPT) -c $< -o $@

pocketsnesd: $(OBJS)
	$(GXX) $(COPT) $(OBJS) $(PRELIBS) -o $@

pocketsnes: pocketsnesd
	$(STRIP) pocketsnesd -o snes4iphone
tidy:
	rm *.o
	rm iphone/*.o
