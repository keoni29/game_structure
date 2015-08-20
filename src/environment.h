#ifndef __environment
#define __environment
class Environment {
public:
	Environment();
	bool placeCheckSolid(int x, int y) const;
	int placeGetTile(int x, int y) const;
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