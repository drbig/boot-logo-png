#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char *argv[]) {
  SDL_Surface *logo_img;
  int sleep_ms = 0;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <sleep_ms> <image.png>\n", argv[0]);
    return 1;
  }
  if ((sleep_ms = atoi(argv[1])) < 300) {
    fprintf(stderr, "Sleep_ms lower than 300 ms: %s\n", sleep_ms);
    return 1;
  }
  if ((logo_img = IMG_Load(argv[2])) == NULL) {
    fprintf(stderr, "Unable to load logo: %s\n", SDL_GetError());
    return 1;
  }

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
    return 2;
  }
  SDL_Surface *screen = SDL_SetVideoMode(320, 240, 16, SDL_SWSURFACE);
  SDL_ShowCursor(SDL_DISABLE);
  SDL_BlitSurface(logo_img, NULL, screen, NULL);
  SDL_Flip(screen);
  SDL_Delay(sleep_ms);
  SDL_Quit();

  return 0;
}
