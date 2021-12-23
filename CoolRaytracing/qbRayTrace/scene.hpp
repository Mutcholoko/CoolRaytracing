#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SDL.h>
#include "qbImage.hpp"

namespace qbRT {
	class Scene {
	public:
		//default constructor
		Scene();

		//perform the rendering
		bool Render(qbImage &outputImage);

	//private functions
	private:


	//private members
	private:

	};
}

#endif // !SCENE_H

