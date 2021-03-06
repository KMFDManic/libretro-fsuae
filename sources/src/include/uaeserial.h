 /*
  * UAE - The Un*x Amiga Emulator
  *
  * uaeserial.device
  *
  * (c) 2006 Toni Wilen
  */

#ifndef UAE_UAESERIAL_H
#define UAE_UAESERIAL_H

uaecptr uaeserialdev_startup (uaecptr resaddr);
void uaeserialdev_install (void);
void uaeserialdev_reset (void);
void uaeserialdev_start_threads (void);

extern int log_uaeserial;

struct uaeserialdata
{
#ifdef _WIN32
    void *handle;
    void *writeevent;
#endif
};

#endif /* UAE_UAESERIAL_H */
