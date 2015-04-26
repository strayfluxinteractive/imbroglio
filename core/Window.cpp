/*
 * Window.cpp
 *
 *  Created on: Apr 26, 2015
 *      Author: cameron
 */

#include "Window.hpp"

Window::Window() {
	setPositionX(SDL_WINDOWPOS_UNDEFINED);
	setPositionY(SDL_WINDOWPOS_UNDEFINED);
	setWidth(640);
	setHeight(480);
	setTitle("Title");
	setFlags(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
}

Window::~Window() {
	SDL_DestroyWindow(getWindow());
	SDL_GL_DeleteContext(_glcontext);
}

int Window::getPositionX() const {
	return _positionX;
}

void Window::setPositionX(int positionX) {
	_positionX = positionX;
}

int Window::getPositionY() const {
	return _positionY;
}

void Window::setPositionY(int positionY) {
	_positionY = positionY;
}

int Window::getWidth() const {
	return _width;
}

void Window::setWidth(int sizeX) {
	_width = sizeX;
}

int Window::getHeight() const {
	return _height;
}

void Window::setHeight(int sizeY) {
	_height = sizeY;
}

void Window::create() {
	// Create a window. Window mode MUST include SDL_WINDOW_OPENGL for use with OpenGL.
	setWindow(
			SDL_CreateWindow(getTitle().c_str(), getPositionX(), getPositionY(),
					getWidth(), getHeight(), getFlags()));

	_glcontext = SDL_GL_CreateContext(getWindow());
}

const std::string& Window::getTitle() const {
	return _title;
}

void Window::setTitle(const std::string& title) {
	this->_title = title;
}

SDL_Window* Window::getWindow() {
	return _window;
}

void Window::setWindow(SDL_Window* window) {
	_window = window;
}

Uint32 Window::getFlags() const {
	return _flags;
}

void Window::setFlags(Uint32 flags) {
	this->_flags = flags;
}
