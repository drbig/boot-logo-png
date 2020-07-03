#include <stdio.h>

#include <SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char **argv) {
  SDL_Surface *img_ready;
  int retVal = SDL_Init(SDL_INIT_VIDEO);
  if (retVal < 0) {
    printf("SDL_Init! SDL_Error: %s\n", SDL_GetError());
  } else {
    SDL_Surface *screen = SDL_SetVideoMode(320, 240, 16, SDL_SWSURFACE);
    if (screen == NULL) {
      printf("SDL_SetVideoMode! SDL_Error: %s\n", SDL_GetError());
    } else {
      SDL_Surface *img = IMG_Load("/mnt/drbig/image-16-rgb565.bmp");
      if (img == NULL) {
        printf("IMG_Load! SDL_Error: %s\n", SDL_GetError());
      } else {
        img_ready = SDL_ConvertSurface(img, screen->format, SDL_SWSURFACE);
        if (img_ready == NULL) {
          printf("SDL_ConvertSurface! SDL_Error: %s\n", SDL_GetError());
        } else {
          printf("Ready to SDL_BlitSurface!\n");
          retVal = SDL_BlitSurface(img_ready, NULL, screen, NULL);
          if (retVal < 0) {
            printf("SDL_BlitSurface! SDL_Error: %s\n", SDL_GetError());
          } else {
            printf("Done SDL_BlitSurface!\n");
          }
          SDL_Delay(5000);
        }
        SDL_FreeSurface(img);
      }
    }
  }
  SDL_Quit();
  return retVal;
}
