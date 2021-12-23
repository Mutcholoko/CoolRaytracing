#pragma once


#ifndef CAPP_H
#define CAPP_H

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "qbRayTrace/qbImage.hpp"

class CApp {
public:
	CApp();
	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event* event);
	void OnLoop();
	void OnRender();
	void OnExit();

private:
	//instance of qbImage to store the image
	qbImage m_image;

	//SDL STUFF
	bool isRunning;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
};

#endif

