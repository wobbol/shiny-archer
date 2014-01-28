#ifndef CREATE_INCLUDE
#define CREATE_INCLUDE

static int const WINDOW_WIDTH = 640;
static int const WINDOW_HIGHT = 480;
static int const SDL_WINDOW_FLAGS = 0;

SDL_Window* createWindow(const char* name);
SDL_Renderer* createRenderer(SDL_Window* window);
SDL_Texture* createTexture(const char* filename, SDL_Renderer* renderer);

#endif
