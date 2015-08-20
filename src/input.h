#ifndef __input
#define __input
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