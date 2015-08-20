/** Filename: event.h
 ** Author: Koen van Vliet <8by8mail@gmail.com>
 **/
#ifndef __event
#define __event
class Event {
public:
	Event(Input* inputController);
	void step();
private:
	Input* in;
};
#endif