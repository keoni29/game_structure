#include <iostream>
#include "gameobject.h"

extern int TILESIZE;

using namespace std;

GameObject::GameObject(){

}

GameObject::~GameObject(){

}

Player::Player(Environment* env) : env(env), vspeed(0), hspeed(0) {
	x = 0;
	y = 30;
}

Player::~Player() {

}

void GameObject::createEvent() {

}

void Player::createEvent() {

}

void GameObject::setTexture(SDL_Texture* t) {
	tex = t;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
}

void GameObject::inputEvent(Key k) {

}

void GameObject::stepEvent() {
	
}

void Player::inputEvent(Key k) {
	cout << "Player: InputEvent with key" << k.code << "." << endl;
	if(k.direction == key_down) {
		switch(k.code) {
			case move_left:
			cout << "Player: START moving left!" << endl;
			hspeed = -maxSpeed;
			break;
			case move_right:
			cout << "Player: START moving right!" << endl;
			hspeed = maxSpeed;
			break;
			case move_up:
			cout << "Player: START moving up!" << endl;
			vspeed = -maxSpeed;
			break;
			case move_down:
			cout << "Player: START moving down!" << endl;
			vspeed = maxSpeed;
			break;
		}
	} else {
		switch(k.code) {
			case move_left:
			cout << "Player: Stop moving left!" << endl;
			if(hspeed < 0)
				hspeed = 0;
			break;
			case move_right:
			cout << "Player: Stop moving right!" << endl;
			if(hspeed > 0)
				hspeed = 0;
			break;
			case move_up:
			cout << "Player: Stop moving up!" << endl;
			if(vspeed < 0)
				vspeed = 0;
			break;
			case move_down:
			cout << "Player: Stop moving down!" << endl;
			if(vspeed > 0)
				vspeed = 0;
			break;
		}
	}
}

void Player::stepEvent() {
	x+= hspeed;
	y+= vspeed;
}