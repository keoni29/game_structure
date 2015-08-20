#ifndef __renderer
#define __renderer
/* Renderer class will take care of all graphics rendering */
class Renderer {
public:
	Renderer();
	~Renderer();
	bool init(SDL_Window* window);
	void render();
	void setEnvironment(Environment* e);
	void setTileSet(SDL_Texture* s);
	SDL_Texture* loadTexture(std::string);
private:
	SDL_Texture* tileSet = NULL;
	SDL_Renderer* hwRenderer = NULL;
	const Environment* env = NULL;
};
#endif