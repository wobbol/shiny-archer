#include <SDL2/SDL.h>
#include "getError.h"
#include "create.h"
SDL_Window* createWindow(const char *name)
{
  SDL_Window *window = NULL; 
  window = SDL_CreateWindow(name,
SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HIGHT, SDL_WINDOW_FLAGS);
  if (window == NULL)        
    {
      getError("unable to create window ");
      SDL_Quit();
      return NULL;
    }
  return window;
}

SDL_Renderer* createRenderer(SDL_Window* window)
{
  SDL_Renderer* renderer = NULL;
  renderer = SDL_CreateRenderer(window, -1, 0);
  if(renderer == NULL)
    {
      getError("Failed to create render-er(f-ing sdl)");
      return 0;
    }   
  return renderer;
}

SDL_Texture* createTexture(const char* filename,SDL_Renderer* renderer)
{
  SDL_Surface* tmpSurface = NULL;
  tmpSurface = SDL_LoadBMP(filename);
  if(tmpSurface == NULL)
    {
    getError("Failed to load image to temp surface");
      return NULL;
    }
  SDL_Texture* texture = NULL;
  texture = SDL_CreateTextureFromSurface(renderer,tmpSurface);
  if(texture == NULL)
    {
      getError("Failed to create texture from surface");
	     SDL_GetError() );
      return NULL;
    }          
  SDL_FreeSurface(tmpSurface);
  return texture;
}
