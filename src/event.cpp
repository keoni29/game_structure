/** Filename: event.cpp
 ** Author: Koen van Vliet <8by8mail@gmail.com>
 **/
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "input.h"
#include "event.h"

using namespace std; 

Event::Event(Input* inputController){
	in = inputController;
}

void Event::step(){
	Key e;
	while(in->pollInput(&e)) {
		cout << "Input trigger: " << e.code;
		if (e.direction) {
			cout << "Down";
		} else {
			cout << "Up";
		}
		cout << endl;
	}
}