#ifndef LIBRETRO_HATARI_H
#define LIBRETRO_HATARI_H

#include "sysconfig.h"
#include "sysdeps.h"
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "libco.h"

extern cothread_t mainThread;
extern cothread_t emuThread;


#define LOGI printf

#define TEX_WIDTH 400
#define TEX_HEIGHT 300

extern int retrow; 
extern int retroh;
extern int retrox; 
extern int retroy;
extern int retrop;
extern int retroo;
extern int retrocw;
extern int retroch;
extern int CROP_WIDTH;
extern int CROP_HEIGHT;

inline static void retrosetpixel(void *buf, int x, int y, int c) {
  if (x>=retrox && y>=retroy && x<retrocw && y<retroch) {
    void *p=(char *)buf + (x-retrox)*retrop + (y-retroy)*retroo;
    switch (retrop) {
    case 2: *(short *)p =c; break;
    case 4: *(int *)p =(((c>>(5+6)) & 0x1f) <<(16+3)) | (((c>>(6)) & 0x1f) <<(8+3)) | (((c>>(0)) & 0x3f) <<(0+2)); break;
    }
  }
}

#define NPLGN 10
#define NLIGN 5
#define NLETT 5

#define XSIDE  (CROP_WIDTH/NPLGN -1)
#define YSIDE  (CROP_HEIGHT/8 -1)

#define YBASE0 (CROP_HEIGHT - NLIGN*YSIDE -8)
#define XBASE0 0+4+2
#define XBASE3 0
#define YBASE3 YBASE0 -4

#define STAT_DECX 120
#define STAT_YSZ  20

#define RGB565(r, g, b)  (((r) << (5+6)) | ((g) << 6) | (b))

//#define TCHAR char /* from sysdeps.h */
//int umain (int argc, TCHAR **argv);
#endif
