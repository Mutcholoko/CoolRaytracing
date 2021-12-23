#pragma once


#ifndef CAPP_H
#define CAPP_H

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "qbRayTrace/qbImage.hpp"
#include "qbRayTrace/scene.hpp"

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

	//instance of scene class
	qbRT::Scene m_scene;

	//SDL STUFF
	bool isRunning;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
};

#endif

