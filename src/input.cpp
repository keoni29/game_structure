/** Filename: input.cpp
 ** Author: Koen van Vliet <8by8mail@gmail.com>
 **/

#include <iostream>
#include "input.h"

using namespace std;

Input::Input(){
	keyMap.push_back(SDLK_UP);
	keyMap.push_back(SDLK_DOWN);
	keyMap.push_back(SDLK_LEFT);
	keyMap.push_back(SDLK_RIGHT);
	cout << "Created keyMap with size " << keyMap.size() << "." << endl;
}

bool operator ==(const Key&k1, const Key &k2) {
	return (k1.code == k2.code && k1.direction == k2.direction);
}

bool Input::process(){
	bool running = true;
	while( SDL_PollEvent( &e ) != 0 )
	{
		if( e.type == SDL_QUIT )
		{
			cout << "Quit signal received." << endl;
			running = false;
		} else if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
			for(int i = 0; i < keyMap.size(); i++){
				if (e.key.keysym.sym == keyMap.at(i)) {
					inputStack.push_back({i, true});
				}
			}
		} else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
			for(int i = 0; i < keyMap.size(); i++){
				if (e.key.keysym.sym == keyMap.at(i)) {
					inputStack.push_back({i, false});
				}
			}
		}
	}
	return running;
}

bool Input::pollInput(Key* k) {
	if (inputStack.size() > 0) {
		*k = inputStack.back();
		inputStack.pop_back();
		return true;
	}
	return false;
}