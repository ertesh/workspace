// App.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <string>
#include "ImagePainter.h"
#include "FormulaGenerator.h"
#include "SDL.h"

using std::cout;
using std::endl;

class WindowManager {
private:
	SDL_Window *sdlWindow;
	int _width;
	int _height;
public:
	WindowManager() {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			throw new std::exception("SDL_Init Error");
		}
	}

	~WindowManager() {
		SDL_Quit();
	}

	void CreateWindow(int width, int height) {
		_width = width;
		_height = height;
		sdlWindow = SDL_CreateWindow("Hello World!", 100, 100, _width, _height, SDL_WINDOW_SHOWN);
		if (sdlWindow == nullptr){
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			throw new std::exception("SDL_CreateWindow Error");
		}
	}

	void RunMainLoop() {
		SDL_Event e;
		while (SDL_WaitEvent(&e))
		{
			if (e.type == SDL_KEYDOWN) // && e.key.keysym.sym == SDLK_ESCAPE) 
				break;
			if (e.type == SDL_QUIT)
				break;
		}
	}

	void PaintImage(const ImageData& image) {
		SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);

		SDL_Texture* sdlTexture = SDL_CreateTexture(sdlRenderer,
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			640, 480);

		SDL_Surface *sdlSurface = SDL_CreateRGBSurface(0, _width, _height, 32,
			0x00FF0000,
			0x0000FF00,
			0x000000FF,
			0xFF000000);
		Uint32 *myPixels = (Uint32*)sdlSurface->pixels;
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {
				myPixels[i * _width + j] = SDL_MapRGBA(sdlSurface->format, image.data[j][i].red, image.data[j][i].green,
					image.data[j][i].blue, image.data[j][i].alpha);
			}
		}
		SDL_UpdateTexture(sdlTexture, NULL, myPixels, 640 * sizeof(Uint32));
		SDL_RenderClear(sdlRenderer);
		SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
		SDL_RenderPresent(sdlRenderer);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	WindowManager manager;
	manager.CreateWindow(640, 480);
	ImagePainter painter(640, 480);
	FormulaGenerator generator;
	auto red = generator.createFormula(10);
	auto green = generator.createFormula(10);
	auto blue = generator.createFormula(10);
	std::cout << red->toString() << endl << green->toString() << endl << blue->toString() << endl;
	ImageData image = painter.CreateFromFormula(*red, *green, *blue);
	manager.PaintImage(image);
	manager.RunMainLoop();
}