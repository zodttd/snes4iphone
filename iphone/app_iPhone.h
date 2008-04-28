/*

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; version 2
 of the License.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#ifndef APP_IPHONE_H
#define APP_IPHONE_H

#import <CoreSurface/CoreSurface.h>
#import <AudioToolbox/AudioQueue.h>

#define INP_BUTTON_UP				(0)
#define INP_BUTTON_LEFT				(2)
#define INP_BUTTON_DOWN				(4)
#define INP_BUTTON_RIGHT			(6)
#define INP_BUTTON_START			(8)
#define INP_BUTTON_SELECT			(9)
#define INP_BUTTON_L				(10)
#define INP_BUTTON_R				(11)
#define INP_BUTTON_HARDLEFT			(12)
#define INP_BUTTON_HARDRIGHT		(13)
#define INP_BUTTON_HARDDOWN			(14)
#define INP_BUTTON_HARDUP			(15)
#define INP_BUTTON_L2				(22)
#define INP_BUTTON_R2				(23)
#define INP_BUTTON_STICK_PUSH		(27)

#define BIT_U			(1<<INP_BUTTON_UP)
#define BIT_D			(1<<INP_BUTTON_DOWN)
#define BIT_L 			(1<<INP_BUTTON_LEFT)
#define BIT_R		 	(1<<INP_BUTTON_RIGHT)
#define BIT_SEL			(1<<INP_BUTTON_SELECT)
#define BIT_ST			(1<<INP_BUTTON_START)
#define BIT_LPAD		(1<<INP_BUTTON_L)
#define BIT_RPAD		(1<<INP_BUTTON_R)
#define BIT_HARDA		(1<<INP_BUTTON_HARDRIGHT)
#define BIT_HARDB		(1<<INP_BUTTON_HARDDOWN)
#define BIT_HARDX		(1<<INP_BUTTON_HARDUP)
#define BIT_HARDY		(1<<INP_BUTTON_HARDLEFT)
#define BIT_VOL_UP		(1<<INP_BUTTON_L2)
#define BIT_VOL_DOWN	(1<<INP_BUTTON_R2)
#define BIT_PUSH		(1<<INP_BUTTON_STICK_PUSH)

#define BIT_A			BIT_HARDA
#define BIT_B			BIT_HARDB
#define BIT_X			BIT_HARDX
#define BIT_Y			BIT_HARDY

#define gp2x_flipscreen()

typedef unsigned char byte;

struct app_Preferences {
    byte frameSkip;
    byte debug;
    byte canDeleteROMs;
    byte transparency;
    byte landscape;
    byte allowSuspend;
    byte scaled;
    byte muted;
    byte selectedSkin;
};

void setDefaultPreferences();
int app_SavePreferences();
int app_LoadPreferences();

/* STUBs to emulator core */

void *app_Thread_Start(void *args);
void *app_Thread_Resume(void *args);
void app_Halt(void);
void app_Resume(void);
int app_LoadROM(const char *fileName);
void app_DeleteTempState(void);
void app_SetSvsFile(char* filename);
int app_OpenSound(int samples_per_sync, int sample_rate);
void app_CloseSound(void);
void app_StopSound();
void app_StartSound();
unsigned long joystick_read();
FILE* fopen_home(char* filename, char* fileop);

extern byte IS_DEBUG;
extern byte IS_CHANGING_ORIENTATION;
extern unsigned short  *BaseAddress;
extern int __screenOrientation;
extern struct app_Preferences preferences;
extern unsigned short *videobuffer;
extern int   __emulation_run;

/* Audio Resources */
#define AUDIO_BUFFERS 2
#define AUDIO_PRECACHE 3
#define WAVE_BUFFER_SIZE 735
#define WAVE_BUFFER_BANKS 25

typedef struct AQCallbackStruct {
    AudioQueueRef queue;
    UInt32 frameCount;
    AudioQueueBufferRef mBuffers[AUDIO_BUFFERS];
    AudioStreamBasicDescription mDataFormat;
} AQCallbackStruct;

#ifndef GUI_DEBUG
#define LOGDEBUG(...) while(0){}
#else
void LOGDEBUG(const char *text, ...);
#endif

#endif
