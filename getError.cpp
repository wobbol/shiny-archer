#include <SDL2/SDL.h>


void getError(const char* mesg){
printf("%s SDL_GetError(): %s\n",mesg,SDL_GetError());
}
