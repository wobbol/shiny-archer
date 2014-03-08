#include <SDL2/SDL.h>


void getError(const char* mesg){
printf(mesg);
printf("SDL_GetError(): %s\n",SDL_GetError());
}
