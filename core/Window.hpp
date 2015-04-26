/*
 * Window.hpp
 *
 *  Created on: Apr 26, 2015
 *      Author: cameron
 */

#ifndef STRAYFLUXINTERACTIVE_IMBROGLIO_CORE_WINDOW_HPP_
#define STRAYFLUXINTERACTIVE_IMBROGLIO_CORE_WINDOW_HPP_
#include <string>
#include "latinga/sdl2/include/sdl.h"
#include "latinga/sdl2/include/sdl_opengl.h"
class Window {
public:
	Window();
	virtual ~Window();
	int getPositionX() const;
	void setPositionX(int positionX);
	int getPositionY() const;
	void setPositionY(int positionY);
	int getWidth() const;
	void setWidth(int width);
	int getHeight() const;
	void setHeight(int height);

	void create();
	const std::string& getTitle() const;
	void setTitle(const std::string& title);
	SDL_Window* getWindow();
	void setWindow(SDL_Window* window);
	Uint32 getFlags() const;
	void setFlags(Uint32 flags);

private:
	std::string _title;
	int _positionX;
	int _positionY;
	int _width;
	int _height;
	SDL_Window *_window;
	Uint32 _flags;
	SDL_GLContext _glcontext;

};


#endif /* STRAYFLUXINTERACTIVE_IMBROGLIO_CORE_WINDOW_HPP_ */
