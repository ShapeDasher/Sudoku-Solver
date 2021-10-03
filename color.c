/*
 * =============================================================================
 *       Filename:  color.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/01/2021 11:33:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "colors.h"
SDL_Event event;


int main()
{
        SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
        LoadIMG("File.bmp");
        SDL_Quit();
        return 0;
}
void LoadIMG(char * name)
{
        SDL_Surface *image = SDL_LoadBMP(name);
        SDL_PixelFormat *imageNewFormat = SDL_AllocFormat(
                                            SDL_PIXELFORMAT_ARGB8888);
        image = SDL_ConvertSurface(image, imageNewFormat,0);
        greyLevels(image);
        black_and_white(image);
}
void greyLevels(SDL_Surface * image)
{
        Uint8 r = 0, b = 0, g = 0;
        Uint32 * pixels = (Uint32 *)image->pixels;
        for(int x =0; x < image->w; x++)
        {
                for(int y = 0; y < image->h ; y++)
                {
                        //From dzone.com/articles/converting-an-image
                        //-to-grayscale-using-sdl2
                        Uint32 pixel = pixels[y * image->w + x];
                        r = pixel >> 16 & 0xff;
                        g = pixel >> 8 & 0xff;
                        b = pixel & 0xff;
                        Uint8 grey = (r + g + b)/3;
                        pixel = (0xff << 24)| (grey << 16) | (grey << 8) | grey;
                        pixels[y * image->w + x] = pixel;
                }
        }
        SDL_SaveBMP(image,"greyLVLS.bmp");
}

void black_and_white(SDL_Surface * image)
{
        Uint8 r = 0, b = 0, g = 0;
        Uint32 * pixels = (Uint32 *)image->pixels;
        for(int x =0; x < image->w; x++)
        {
                for(int y = 0; y < image->h ; y++)
                {
                        Uint32 pixel = pixels[y * image->w + x];
                        r = pixel >> 16 & 0xff;
                        g = pixel >> 8 & 0xff;
                        b = pixel & 0xff;
                        Uint8 grey = (r + g + b)/3;
                        if (grey < 127)
                                pixel = (255 << 24)| (0 << 16) | (0 << 8) |
                                    0 ;
                        else
                                pixel = (255 << 24)| (255 << 16) | (255 << 8) |
                                    255 ;
                        pixels[y * image->w + x] = pixel;
                }
        }
        SDL_SaveBMP(image,"B&W.bmp");
}
