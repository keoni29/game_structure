/** Filename: event.cpp
 ** Author: Koen van Vliet <8by8mail@gmail.com>
 **/
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "input.h"
#include "gameobject.h"
#include "event.h"

using namespace std; 

Event::Event(Input* inputController){
	in = inputController;
}

void Event::registerGameObject(GameObject* g) {
	eventObject.push_back(g);
}

void Event::step(){
	Key k;

	/* Process input triggers */
	while(in->pollInput(&k)) {
		cout << "Input trigger: " << k.code;
		if (k.direction) {
			cout << "Down";
		} else {
			cout << "Up";
		}
		cout << endl;
		for(int i = 0; i < eventObject.size(); i ++)
		{
			cout << "Triggering event for game object #" << i << "." << endl;
			eventObject.at(i)->inputEvent(k);
		}
	}

	/* Do one step for every game object */
	for(int i = 0; i < eventObject.size(); i ++)
	{
		eventObject.at(i)->stepEvent();
	}
}