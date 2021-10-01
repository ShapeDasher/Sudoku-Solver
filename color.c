/*
 * =====================================================================================
 *
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
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

int main()
{

        SDL_Surface *image = SDL_LoadBMP("File.bmp");
        Uint32 *pixels = (Uint32 *)image->pixels;
        Uint32 pix = pixels[0];
        const SDL_PixelFormat * fmt = image->format;
        Uint8 r = 0, b = 0, g = 0;
        SDL_GetRGB(pix,fmt,&r,&g,&b );
        return 0;

        //printf("Red : %i, Green : %i, Blue : %i \n", color.r, color.g, color.b);
        //printf("Grey Level : %d \n", (color.r + color.g + color.b) / 3);
}
