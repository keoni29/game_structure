/** Filename: environment.h
 ** Author: Koen van Vliet <8by8mail@gmail.com>
 **/

#ifndef __environment
#define __environment
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <vector>
class Environment {
public:
	Environment();
	bool placeCheckSolid(int x, int y) const;
	int gridGetTile(int gx, int gy) const;
	void placeSetTile(int x, int y, int newId);
	void loadFile(FILE* worldFile);
	void loadLevel(int level);
	int getWidth() const;
	int getHeight() const;
private:
	int width, height;
	int packSize;
	int roomX, roomY,roomNumber;
	std::vector<char> worldBuffer;
	std::vector<char> tileMap;
	std::vector<int> tileFrame;
};
#endif