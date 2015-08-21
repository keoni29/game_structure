#ifndef __gameobject
#define __gameobject
class GameObject {
public:
	GameObject();
	~GameObject();
	virtual void inputEvent(Key k) = 0;
	virtual void stepEvent() = 0;
private:
};

class Player: public GameObject {
public:
	Player();
	~Player();
	void inputEvent(Key k);
	void stepEvent();
private:
	int x, y;
};
#endif