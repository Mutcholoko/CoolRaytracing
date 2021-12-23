#include "CApp.h"

// default constructor
CApp::CApp() {
	isRunning = true;
	pWindow = NULL;
	pRenderer = NULL;
}

bool CApp::OnInit() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	pWindow = SDL_CreateWindow("Cool Raytracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (pWindow != NULL) {
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

		//initialize qbImage instance
		m_image.Initialize(800, 600, pRenderer);

		/*
		//create color variations
		//not used anymore, but keeping it here for happiness reasons
		for (int x = 0; x < 800; ++x) {
			for (int y = 0; y < 600; ++y) {
				double red = (static_cast<double>(x) / 800.0) * 255.0;
				double green = (static_cast<double>(y) / 600.0) * 255.0;
				m_image.SetPixel(x, y, red, green, 0.0);
			}
		}*/
	}
	else {
		return false;
	}
	return true;
}

int CApp::OnExecute() {
	SDL_Event event;
	if (OnInit() == false) {
		return -1;
	}

	while (isRunning) {
		while (SDL_PollEvent(&event) != 0) {
			OnEvent(&event);
		}
	OnLoop();
	OnRender();
	}
}

void CApp::OnEvent(SDL_Event* event) {
	if (event->type == SDL_QUIT) {
		isRunning = false;
	}
}

void CApp::OnLoop() {

}

void CApp::OnRender() {
	//set bg to white
	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(pRenderer);

	//Render scene
	m_scene.Render(m_image);


	//display image
	m_image.Display();

	SDL_RenderPresent(pRenderer);
}

void CApp::OnExit() {
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = NULL;
	SDL_Quit();
}