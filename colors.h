/*
 * =====================================================================================
 *
 *       Filename:  colors.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/02/2021 05:29:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef COLORS_H
#define COLORS_H
#include <SDL2/SDL.h>
int main();
void Display(SDL_Surface * surface, int w, int h, int x, int y,
             SDL_Window * wind);
void LoadIMG(char*name);
void greyLevels(SDL_Surface * image );
void black_and_white(SDL_Surface * image);
#endif
