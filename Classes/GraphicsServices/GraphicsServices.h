/* iPhone Open SDK - Free Open Source Anti-Apple SDK
 * Copyright (C) 2008  Jay Freeman (saurik)
*/

/*
 *        Redistribution and use in source and binary
 * forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the
 *    above copyright notice, this list of conditions
 *    and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the
 *    above copyright notice, this list of conditions
 *    and the following disclaimer in the documentation
 *    and/or other materials provided with the
 *    distribution.
 * 3. The name of the author may not be used to endorse
 *    or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef GRAPHICSSERVICES_GRAPHICSSERVICS_H_
#define GRAPHICSSERVICES_GRAPHICSSERVICS_H_

#include <mach/port.h>
#import <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CGGeometry.h>

#include <GraphicsServices/GSFont.h>
#include <GraphicsServices/GSWindow.h>

#ifdef __cplusplus
extern "C" {
#endif

struct GSPathInfo {
    /*0x00:13c*/ uint8_t x00; // key
    /*0x01:13d*/ uint8_t x01;
    /*0x02:13e*/ uint8_t x02; // 2=no
    /*0x03:13f*/ uint8_t x03;
    /*0x04:140*/ uint32_t x04;
    /*0x08:144*/ uint32_t x08;
    /*0x0c:148*/ CGPoint position;
    /*0x14:14c*/ uint32_t x14;
};

struct GSEventRecord {
    /*0x00:08*/ uint32_t type;
    /*0x04:0c*/ uint32_t subType;
    /*0x08:10*/ CGPoint locationOnScreen;
    /*0x10:18*/ CGPoint locationInWindow;
    /*0x18:20*/ uint64_t timestamp; //(GSCurrentEventTimestamp)
    /*0x20:28*/ uint32_t zero;
    /*0x24:2c*/ uint32_t modifierFlags;
    /*0x28:30*/ uint16_t eventNumber;
    /*0x2a:32*/ uint16_t x2a;
    /*0x2c:34*/ uint32_t size;
};

struct GSEventKeyInfo {
    /*0x30:38*/ uint32_t type;
    /*0x34:3c*/ uint16_t character;
    /*0x38:3e*/ uint16_t characterSet;
    /*0x3a:40*/ uint8_t keyRepeating;
};

struct GSEventHandInfo {
    /*0x30:38:00:5c*/ uint32_t type;
    /*0x34:3c:04:60*/ uint16_t x34;
    /*0x38:3e:06:64*/ uint16_t x38;
    /*0x3a:40:08:68*/ CGPoint x3a;
    /*0x40:48:10:70*/ uint32_t x40; //handInfoScale scales
};

struct GSEventApplicationInfo {
    /*0x30:00*/ uint32_t pid;
    /*0x34:04*/ uint32_t x34;
    /*0x38:08*/ char name[];
};

struct GSEventRecordInfo {
    /*0x30:38:00:5c*/ struct GSEventHandInfo handInfo;
    /*0x44:4c:14:74*/ uint32_t x44;
    /*0x48:50:18:78*/ uint32_t x48; //handInfoScale scales
    /*0x4c:54:1c:7c*/ uint32_t x4c;
    /*0x50:58:20*/ uint8_t x50;
    /*0x51:59:21*/ uint8_t pathPositions;
    /*0x52:5a:22*/ uint16_t x52;
    /*0x54:5c:24*/ struct GSPathInfo pathInfo[];
};

/*struct __GSEvent {
    struct CFRuntimeBase base_;
    struct GSEventRecord record_;
};*/

typedef struct __GSEvent *GSEventRef;

#define GSEventTypeKeyDown                  0x000d

#define GSEventTypeAccelerometer            0x0017
#define GSEventTypeProximityStateChanged    0x0018
#define GSEventTypeDeviceOrientationChanged 0x0032
// 0x03c:loc_0018ac preferences

#define GSEventTypeMenuButtonDown           0x03e8
#define GSEventTypeMenuButtonUp             0x03e9
#define GSEventTypeRingerChanged0           0x03f4
#define GSEventTypeRingerChanged1           0x03f5
#define GSEventTypeLockDevice               0x03f6
#define GSEventTypeStatusBarMouseDown       0x03f7
#define GSEventTypeStatusBarMouseDragged    0x03f8
#define GSEventTypeStatusBarMouseUp         0x03f9
#define GSEventTypeLockButtonDown           0x03f2
#define GSEventTypeLockButtonUp             0x03f3
#define GSEventTypeHeadsetButtonDown        0x03fa
#define GSEventTypeHeadsetButtonUp          0x03fb

#define GSEventTypeVibrateForDuration       0x044c
#define GSEventTypeSetBacklightFactor       0x044e
#define GSEventTypeSetBacklightLevel        0x044f

#define GSEventTypeApplicationStarted                  0x07d0
#define GSEventTypeAnotherApplicationFinishedLauncing  0x07d2
#define GSEventTypeApplicationTerminateWithStatus      0x07d3
#define GSEventTypeApplicationSuspended                0x07d4
// 0x07d5:loc_000550 internal url
// 0x07d6:loc_000a20 external url
#define GSEventTypeApplicationExited                   0x07d7
#define GSEventTypeApplicationShowHideSettings         0x07d8
#define GSEventTypeQuitTopApplication                  0x07d9
#define GSEventTypeOtherApplicationWillSuspend         0x07da
#define GSEventTypeApplicationSuspendedSettingsUpdated 0x07db

#define GSEventTypeResetIdleTimer                      0x0898
#define GSEventTypeResetIdleDuration                   0x0899
#define GSEventTypeDumpUIHierarchy                     0x09c4
#define GSEventTypeDumpScreenContents                  0x09c5
#define GSEventTypeProcessScriptEvent                  0x0a8c

#define GSEventTypeMouse                               0x0bb9

#define GSEventTypeAccessoryAvailabilityChanged        0x0fa0
#define GSEventTypeAccessoryKeyStateChanged            0x0fa1
#define GSEventTypeAccessory                           0x0fa2

#define GSEventTypeOutOfLineDataRequest                0x1388
#define GSEventTypeUrgentMemoryWarning                 0x1770
#define GSEventTypeOutOfLineDataResponse              0x10001

#define GSMouseEventTypeDown    0x1
#define GSMouseEventTypeDragged 0x2
#define GSMouseEventTypeUp      0x6
#define GSMouseEventTypeCancel  0x8

#define _PurpleSystemEventPortName "PurpleSystemEventPort"

mach_port_name_t GSCopyPurpleSystemEventPort(void);
uint64_t GSCurrentEventTimestamp(void);
struct GSEventHandInfo GSEventGetHandInfo(GSEventRef event);
struct CGRect GSEventGetLocationInWindow(GSEventRef event);
struct GSPathInfo GSEventGetPathInfoAtIndex(GSEventRef event, unsigned index);
mach_port_name_t GSGetPurpleNamedPort(CFStringRef name);
void GSSendEvent(struct GSEventRecord *record, mach_port_name_t port);
void GSSendSystemEvent(struct GSEventRecord *record);
struct GSEventRecord *_GSEventGetGSEventRecord(GSEventRef event);

CFArrayRef GSSystemGetCapability(CFStringRef type);
extern CFStringRef const kGSDisplayIdentifiersCapability;

#ifdef __cplusplus
}
#endif

#endif//GRAPHICSSERVICES_GRAPHICSSERVICS_H_
