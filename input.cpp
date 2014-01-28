#include <SDL2/SDL.h> 
#include "input.h"
#include "create.h"    //for window size deffinitions


int getInput( input *kbdMouse, SDL_Event event)
{
  
  SDL_WaitEvent(&event);        
        
  switch(event.type)        
    {        
    case SDL_QUIT:        
      kbdMouse->quit = true;        
      break;        
    }        
  if(event.type == SDL_KEYDOWN)
    {
      switch (event.key.keysym.sym)
	{
	case SDLK_q:
	  kbdMouse->ablity1 = 1;
	  break;

	case SDLK_w:
	  kbdMouse->ablity2 = 1;
	  break;

	case SDLK_e:
	  kbdMouse->ablity3 = 1;
	  break;

	case SDLK_r:
	  kbdMouse->ablity4 = 1;
	  break;

	case SDLK_t:
	  if( kbdMouse->toggleTrapMouse == 1 )
	    kbdMouse->toggleTrapMouse = 0;
	  else 
	    kbdMouse->toggleTrapMouse = 1;
	  break;

	case SDLK_LEFT:
	  kbdMouse->camera_x--;
	  break;

	case SDLK_RIGHT:
	  kbdMouse->camera_x++;
	  break;
	}
    }
  if(event.type == SDL_MOUSEBUTTONDOWN)
    {
      if(event.button.button == SDL_BUTTON_LEFT)
	printf("leftmb\n");
    }
  if(event.type == SDL_MOUSEMOTION)
    printf("mouse x:%i\ty:%i\n",event.motion.x,event.motion.y);

}
int doWindowChanges(input *kbdMouse,SDL_Window *window)
{
  if( kbdMouse->toggleTrapMouse == 1 )
    {
      SDL_SetWindowGrab(window,SDL_TRUE);
      SDL_SetRelativeMouseMode(SDL_TRUE);
    }
  else
    {
      SDL_SetWindowGrab(window,SDL_FALSE);
      SDL_SetRelativeMouseMode(SDL_FALSE);
    }
}
int doAblities(input *kbdMouse)
{
  if( kbdMouse->ablity1 == 1)
    printf("nasus gp qq\n"); 
  if( kbdMouse->ablity2 == 1)
    printf("warwick\n");
  if( kbdMouse->ablity3 == 1)
    printf("wee my e\n");
  if( kbdMouse->ablity4 == 1)
    printf("rawe tahts my r\n");
}
int doCameraMove(input *kbdMouse,SDL_Rect *camera,int texW, int texH)
{
  if(kbdMouse->camera_x >= texW-WINDOW_WIDTH)
    kbdMouse->camera_x = 0;
  else if(kbdMouse->camera_x < 0)
    kbdMouse->camera_x = texW-WINDOW_WIDTH;
  camera->x = kbdMouse->camera_x;
}
int clearInput(input *kbdMouse)
{
  kbdMouse->ablity1 = 0;
  kbdMouse->ablity2 = 0;
  kbdMouse->ablity3 = 0;
  kbdMouse->ablity4 = 0;
 
  kbdMouse->arrowLeft = 0;
  kbdMouse->arrowRight = 0;
}  
// ---------0--------------
