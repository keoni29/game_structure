/** Filename: renderer.cpp
 ** Author: Koen van Vliet <8by8mail@gmail.com>
 **/

#include <iostream>
#include "renderer.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int TILESIZE;

using namespace std;

Renderer::Renderer() {

}

void Renderer::registerGameObject(GameObject* g) {
	drawObject.push_back(g);
	int xx = g->x;
	int yy = g->y;
	int ww = g->w;
	int hh = g->h;
	cout << "Renderer: Registered object with x=" << xx << ", y=" << yy << ", w=" << ww << ", h=" << hh << endl;
}

void Renderer::setTileSet(SDL_Texture* s) {
	tileSet = s;
}


void Renderer::setEnvironment(Environment* e) {
	env = e;
}

void Renderer::render() {
	SDL_SetRenderDrawColor(hwRenderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(hwRenderer);

	int width = env->getWidth();
	int height = env->getHeight();
	for(int yy = 0; yy < height; yy++)
	{
		for(int xx = 0; xx < width; xx++)
		{
			int tid = env->gridGetTile(xx,yy);
			if (tid)
			{
				//int f = tileFrame->at(tid-1);
				int f = 0;
				SDL_Rect clip = {f * TILESIZE, (tid - 1) * TILESIZE, TILESIZE, TILESIZE};
				SDL_Rect rect = {xx * TILESIZE, yy * TILESIZE, TILESIZE, TILESIZE};
				SDL_RenderCopy( hwRenderer, tileSet, &clip, &rect );
			}
		}
	}

	for(int i = 0; i < drawObject.size(); i++) {
		GameObject* g = drawObject.at(i);
		SDL_Texture* tex = g->tex;
		int xx = g->x;
		int yy = g->y;
		int ww = g->w;
		int hh = g->h;
		SDL_Rect rect = {xx, yy, ww, hh};
		SDL_RenderCopy( hwRenderer, tex, NULL, &rect );
	}

	SDL_RenderPresent(hwRenderer);
}

bool Renderer::init(SDL_Window* window) {
	bool success = true;
	// Create renderer for window
	hwRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if( hwRenderer == NULL )	{
		success = false;
	}

	// Set renderer color (default black)
	SDL_SetRenderDrawColor( hwRenderer, 0x00, 0x00, 0x00, 0xFF );

	// Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags) & imgFlags))	{
		success = false;
	}

	return success;
}

SDL_Texture* Renderer::loadTexture( std::string path )
{ 
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{ 
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{ 
		//Create texture from surface pixels 
		newTexture = SDL_CreateTextureFromSurface( hwRenderer, loadedSurface ); 
		if( newTexture == NULL ) 
		{ 
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		//Discard the surface
		SDL_FreeSurface( loadedSurface ); 
	}
	return newTexture; 
}

Renderer::~Renderer() {
	//Destroy window	
	SDL_DestroyRenderer( hwRenderer );
	hwRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}