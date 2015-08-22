/** Filename: renderer.h
 ** Author: Koen van Vliet <8by8mail@gmail.com>
 **/

#ifndef __renderer
#define __renderer
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include "environment.h"
#include "gameobject.h"
/* Renderer class will take care of all graphics rendering */
class Renderer {
public:
	Renderer();
	~Renderer();
	bool init(SDL_Window* window);
	void render();
	void setEnvironment(Environment* e);
	void setTileSet(SDL_Texture* s);
	SDL_Texture* loadTexture(std::string);
	void registerGameObject(GameObject* g);
private:
	SDL_Texture* tileSet = NULL;
	SDL_Renderer* hwRenderer = NULL;
	const Environment* env = NULL;
	std::vector<GameObject*>drawObject;
};
#endif