#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <unistd.h>

void window_fullscreem(Window *window){
}

int main(void) {

  Display *display;
  XEvent ev;

  if (!(display = XOpenDisplay(0x0)))
    return 1;

  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("I")), Mod1Mask,
           DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);

  XGrabButton(display, 1, Mod1Mask, DefaultRootWindow(display), True,
              ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
              GrabModeAsync, GrabModeAsync, None, None);

  for (;;) {
    XNextEvent(display, &ev);
    if (ev.type == KeyPress) {
      if (fork() == 0) {
        if (display)
          close(ConnectionNumber(display));
        setsid();
        char *roficmd[] = {"rofi", "-show", "drun", NULL};
        execvp(roficmd[0], roficmd);
        perror(" failed");
      }
    } else if (ev.type == ButtonPress) {
      break;
    }
  }
  return 0;
}
