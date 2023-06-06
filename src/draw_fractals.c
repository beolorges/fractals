#include "SDL2/SDL.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define LINE_SIZE 8
#define X_INITIAL_POSITION 100
#define Y_INITIAL_POSITION 500
#define PI 3.141592654

typedef struct coordenates {
    float x, y;
} Coordenates;


int main(){
    // TODO: Receber corretamente as entradas S e Angle


    char s[5105] = "F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-FF+F-F-FFF+F+F-FF+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F+F+F-F-FFF+F+F-F-F+F-F-FFF+F+F-F";
    float angle = PI/2;
    float actualAngle = 0;
    Coordenates actualPosition, lineSize;
    lineSize.x = LINE_SIZE;
    lineSize.y = 0;

    actualPosition.x = X_INITIAL_POSITION;
    actualPosition.y = Y_INITIAL_POSITION;

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1500, 1500,
                                          0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    char c = s[0];
    for(int i = 0; c != '\0'; i++){
        c = s[i];
        switch (c){
        case 'F':
            float finalPositionX = actualPosition.x + lineSize.x;
            float finalPositionY = actualPosition.y + lineSize.y;


            SDL_RenderDrawLine(renderer, 
                actualPosition.x, 
                actualPosition.y, 
                finalPositionX, 
                finalPositionY);
            
            actualPosition.x = finalPositionX;
            actualPosition.y = finalPositionY;

            break;

        case '+':
            actualAngle -= angle;

            lineSize.y = sin(actualAngle) * LINE_SIZE;
            lineSize.x = cos(actualAngle) * LINE_SIZE;
            break;

        case '-':
            actualAngle += angle;

            lineSize.y = sin(actualAngle) * LINE_SIZE;
            lineSize.x = cos(actualAngle) * LINE_SIZE;

            break;
        
        default:
            break;
        }

    }

    SDL_RenderPresent(renderer);
 
    SDL_Delay(10000);

}