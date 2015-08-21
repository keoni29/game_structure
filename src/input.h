#ifndef __input
#define __input
enum {
	move_up, move_down, move_left, move_right
};

enum {
	key_down = 1, key_up = 0
};

class Key {
public:
	int code;
	bool direction;
};

class Input {
public:
	Input();
	bool process();
	bool pollInput(Key* e);
private:
	SDL_Event e;
	std::vector<Key> inputStack;
	std::vector<SDL_Keycode> keyMap;
};
#endif