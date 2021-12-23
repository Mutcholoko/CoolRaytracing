#pragma once
#ifndef QBIMAGE_H
#define QBIMAGE_H

#include <string>
#include <vector>
#include <SDL.h>

class qbImage {
	
public: 
	//constructor
	qbImage();

	//destructor
	~qbImage();

	//Initialize image
	void Initialize(const int xSize, const int ySize, SDL_Renderer* pRenderer);

	//set pixel colour
	void SetPixel(const int x, const int y, const double red, const double green, const double blue);

	//return image to display
	void Display();

private:
	Uint32 ConvertColor(const double red, const double green, const double blue);
	void InitTexture();
private:
	//arrays to store image data
	std::vector<std::vector<double>> m_rChannel;
	std::vector<std::vector<double>> m_gChannel;
	std::vector<std::vector<double>> m_bChannel;

	//store dimensions of image
	int m_xSize, m_ySize;

	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
};

#endif