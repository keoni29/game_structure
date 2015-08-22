#ifndef __gameobject
#define __gameobject
#include <SDL2/SDL.h>
#include "input.h"
#include "environment.h"
class GameObject {
public:
	GameObject();
	~GameObject();
	virtual void createEvent();
	virtual void inputEvent(Key k);
	virtual void stepEvent();
	virtual void setTexture(SDL_Texture* t);
	float x, y;
	int w, h;
	SDL_Texture* tex = NULL;
};

class Player: public GameObject {
public:
	Player(Environment* env);
	~Player();
	void createEvent();
	void inputEvent(Key k);
	void stepEvent();
private:
	float hspeed, vspeed, maxSpeed = 3, gravity = 0.2;
	Environment* env;
};
#endif