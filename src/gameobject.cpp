#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "input.h"
#include "gameobject.h"
#include "event.h"

using namespace std;

GameObject::GameObject(){

}

GameObject::~GameObject(){

}

Player::Player() {
	x = 0;
	y = 0;
}
Player::~Player() {

}

void Player::inputEvent(Key k) {
	cout << "Player: InputEvent with key" << k.code << "." << endl;
}

void Player::stepEvent() {
	// Do single step
}