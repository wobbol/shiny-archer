#ifndef INPUT_INCLUDE
#define INPUT_INCLUDE
typedef struct
{
  bool ablity1, ablity2, ablity3, ablity4;
  bool quit;
  bool arrowLeft, arrowRight;
  bool toggleTrapMouse;
  int camera_x;
} input;

int getInput(input &kbdMouse, SDL_Event event);
int doWindowChanges(input &kbdMouse,SDL_Window *window);
int doAblities(input &kbdMouse);
int clearInput(input &kbdMouse);
int doCameraMove(input &kbdMouse,SDL_Rect *camera,int texW, int texH);    //this function RELIES on the size of the window not changeing!!!
#endif
