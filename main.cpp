#include <SDL2/SDL.h>        
#include <iostream>
#include <string>
#include "input.h"
#include "create.h"
#include "getError.h"

using namespace std;  

int init()
{
  return SDL_Init(SDL_INIT_VIDEO);        
}

int main(int argc, char ** argv)        
{              

  if(init())
    {
      getError("Failed to Initalize SDL");
      return 0;
    }  
  SDL_Window *window = createWindow("window name");
  SDL_Renderer *renderer = createRenderer(window);
  SDL_Texture *texture = createTexture("background.bmp",renderer);

  int textureW, textureH;
  SDL_QueryTexture(texture, NULL, NULL, &textureW, &textureH);
  
  input kbdMouse; 
  kbdMouse.ablity1 = 0;
  kbdMouse.ablity2 = 0;
  kbdMouse.ablity3 = 0;
  kbdMouse.ablity4 = 0;
  kbdMouse.quit = 0;
  kbdMouse.arrowLeft = 0;
  kbdMouse.arrowRight = 0;
  kbdMouse.toggleTrapMouse = 0;
  kbdMouse.camera_x = 0;  

  SDL_Rect camera;
  camera.x = 0;
  camera.y = 0;
  camera.w = 640;
  camera.h = 480;

  SDL_Event event; 
 
  while ( !kbdMouse.quit )        
    {        
      getInput(kbdMouse, event);    

      doWindowChanges(kbdMouse,window); 
      doCameraMove(kbdMouse,&camera,textureW,textureH);  
      doAblities(kbdMouse);

      clearInput(kbdMouse);
      

      if(SDL_RenderCopy(renderer,texture,&camera,NULL) < 0 )
	getError("Failed to Rendercopy");
      SDL_RenderPresent(renderer);
    }        
            
  SDL_Quit();        
            
  return 0;        
}
