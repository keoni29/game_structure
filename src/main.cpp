/** Filename: main.cpp
 ** Author: Koen van Vliet <8by8mail@gmail.com>
 **/

/* Include Files */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include <iostream>
#include "environment.h"
#include "renderer.h"
#include "input.h"
#include "event.h"

int TILESIZE = 30;
int SCREEN_WIDTH = TILESIZE * 31;
int SCREEN_HEIGHT = TILESIZE * 18;

using namespace std;

int main() {
	/* Open World file */
	FILE* worldFile = fopen("data/easy", "rb");
	if (worldFile == NULL)
	{
		cout << "Worldfile not found!" << endl;
		return 0;
	}

	/* Create Environment */
	Environment env;
	env.loadFile(worldFile);
	env.loadLevel(0);

	/* Initialize SDL subsystem */
	SDL_Window* gWindow = NULL;
	if(SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0)	{
		cout << "Could not initialize SDL subsystem." << endl;
		return 0;
	}

	/* Create Window */
	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
	gWindow = SDL_CreateWindow(NULL, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if(gWindow == NULL)	{
		cout << "Could not create SDL window." << endl;
		return 0;
	}

	/* Create Renderer */
	Renderer sRenderer;
	if (!sRenderer.init(gWindow)) {
		cout << "Could not initialize Renderer object." << endl;
	}
	sRenderer.setEnvironment(&env);

	/* Load resources */
	SDL_Texture* tileSet = sRenderer.loadTexture("data/tileSheet.png");
	sRenderer.setTileSet(tileSet);

	Input inputController;
	Event eventManager(&inputController);

	/* Main game loop */
	while (inputController.process()) {
		eventManager.step();
		sRenderer.render();
	}

	cout << "Stopping game..." << endl;

	/* Cleaning up */
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	fclose(worldFile);
	return 0;
}
