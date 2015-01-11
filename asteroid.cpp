#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

using namespace std;

class Screen {
  public:
    Screen(); 
    Screen(int screen_width, int screen_height);
    
    void display_image();
    void close_window(void);

    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_Surface* image;

    int width;
    int height;
};

Screen::Screen() {}

Screen::Screen(int screen_width, int screen_height) : width(screen_width), height(screen_height) {
  window = SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
  screenSurface = SDL_GetWindowSurface(window);
  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
}

void Screen::display_image(void) {
  image = SDL_LoadBMP("cool-space-wallpaper.bmp");
  SDL_BlitSurface(image, NULL, screenSurface, NULL);
}

void Screen::close_window(void) {
  SDL_FreeSurface(image);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main(int args, char* argc[]) {
  Screen screen(640,480);
  bool done = false;
  screen.display_image();
  SDL_UpdateWindowSurface(screen.window);
  SDL_Delay(2000);
  screen.close_window();
  return 0;
}
  
  
