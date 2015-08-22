/** Filename: environment.cpp
 ** Author: Koen van Vliet <8by8mail@gmail.com>
 **/
 
#include <iostream>
#include "environment.h"

extern int TILESIZE;

using namespace std;

int Environment::getWidth() const {
	return width;
}

int Environment::getHeight() const {
	return height;
}

void Environment::placeSetTile(int x, int y, int newId) {
	tileMap.at(y * width + x) = newId;
}

Environment::Environment() {

}

void Environment::loadFile(FILE* worldFile)
{
	rewind(worldFile);
	worldBuffer.clear();
	if (worldFile != NULL)
	{
		char buf[200];
		fread(buf, 1, sizeof(buf), worldFile);
		packSize = buf[198] * buf[199];

		width = buf[3];
		height = buf[4];

		while (size_t len = fread(buf, 1, sizeof(buf), worldFile))
			worldBuffer.insert(worldBuffer.end(), buf, buf + len);
		cout << "Loaded  " << worldBuffer.size() << " bytes in worldBuffer..." << endl;
	}
	else
	{
		cout << "Could not load worldFile..." << endl;
	}
}

/* Load single level from worldBuffer into the tileMap */
void Environment::loadLevel(int level)
{
	int offset = level * width * height;
	
	if(level >= 0 && level < packSize)
	{
		tileMap.clear();

		for(int yy = 0; yy < height; yy++)
		{
			for(int xx = 0; xx < width; xx++)
			{
				int i = yy * width + xx + offset;
				int t = worldBuffer.at(i);

				tileMap.push_back(t);
			}
		}
	}
}

bool Environment::placeCheckSolid(int x, int y) const
{
	int tid = gridGetTile(x / TILESIZE, y /TILESIZE);
	return tid >= 3;
}

int Environment::gridGetTile(int gx, int gy) const
{
	if (gx >= 0 && gx < width && gy >=0 && gy < height)
	{
		int tid = tileMap.at(gy * width + gx);
		return tid;
	}
	else
	{
		return -1;
	}
}