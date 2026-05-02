# Mandelbrot Set Visualizer (C + SDL2)

This is a simple project that visualizes the Mandelbrot set using C and SDL2.

It works by mapping each pixel on the screen to a complex number and checking whether that number belongs to the Mandelbrot set. If it does, the pixel is colored white.

## Requirements

- GCC compiler (MinGW recommended for Windows)
- SDL2 library installed

## How to Compile

g++ main.c -Iinclude -Llib -o main.exe -lmingw32 -lSDL2main -lSDL2

## How to Run

main.exe

## Controls

- Close the window to exit the program

## Notes

- The program uses a fixed number of iterations to determine membership.
- There is a delay in rendering (4 seconds).
- The fractal is currently displayed in white color only.

## Things You Can Improve

- Add zoom functionality
- Add colors based on iteration count
- Improve performance by avoiding repeated calculations
- Optimize Mandelbrot calculation (escape early)

## Purpose

This project helps in understanding:
- Complex numbers in C
- Basic graphics using SDL2
- How mathematical formulas can be visualized
