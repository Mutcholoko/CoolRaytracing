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
		m_image.Initialize(1280, 720, pRenderer);

		//create color variations
		for (int x = 0; x < 1280; ++x) {
			for (int y = 0; y < 720; ++y) {
				double red = (static_cast<double>(x) / 1280.0) * 255.0;
				double green = (static_cast<double>(y) / 720.0) * 255.0;
				m_image.SetPixel(x, y, red, green, 0.0);
			}
		}
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