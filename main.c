// g++ main.c -Iinclude -Llib -o main.exe -lmingw32 -lSDL2main -lSDL2
// use this command to run this file

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

#define WIDTH 900
#define HEIGHT 600
#define ITERATION 100
#define LIMIT 100
#define ZOOM 250
#define OFFSET_X 100
#define COLOR_WHITE 0xffffff

bool check_mandelbrot(double real, double imag){
    // function to determine if the complex number is in the madelbrot set or not
    double _Complex c = real + imag *I; // Given complex number
    double _Complex z = 0; // Iteration start form Z= 0

    for(int i=0;i<=ITERATION;i++){
        z = cpow(z,2) + c;
    }

    // checks if Z is inside the limit or not
    return cabs(z) < LIMIT;

}

void visualise_mandelbrot_screen(SDL_Surface *psurface){
    for(int x=0;x<WIDTH; x++){
        for(int y=0;y<HEIGHT;y++){
            // Transformation of the coordinate system
            double r = ((double) (x - WIDTH/2 - OFFSET_X)) / ZOOM;
            double i = - ((double) (y-HEIGHT/2)) / ZOOM;
            if(check_mandelbrot(r,i)){
                SDL_Rect pixel = {x,y,1,1};
                SDL_FillRect(psurface, &pixel, COLOR_WHITE);
            }
        }
    }
}

double cabs(double _Complex number){
    double value = pow(creal(number),2) + pow(cimag(number),2);
    return sqrt(value);
}


int main(int argv, char* argc[]){
    printf("Hello Mandelbrot \n");
    SDL_Init(SDL_INIT_VIDEO); // Initilising the library needed

    // crating the pointer for window and surface
    SDL_Window *pwindow = SDL_CreateWindow("Mandelbrot Set",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0); 
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    // Drawing a rectangle on the screen
    // SDL_Rect rect = {0,0,100,100};
    // SDL_FillRect(psurface, &rect, COLOR_WHITE);
    // SDL_UpdateWindowSurface(pwindow);



    // while loop for exiting the application
    bool application_running = true;
    while(application_running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT: 
                application_running = false;
                break;
            }
            visualise_mandelbrot_screen(psurface);
            SDL_UpdateWindowSurface(pwindow);
            SDL_Delay(4000);
        }
    }



    // Clean up
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
    
    return 0;
}