/*
 * Environment.h
 *
 *  Created on: 9 mar 2016
 *      Author: Michau
 */

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "SDLSetup.h"
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Sprite.h"
#include "Tree.h"

class Environment {
private:
	Sprite *m_grass[4][4];
	std::vector<Tree*> m_trees;
	SDL_Setup *m_sdlSetup;

	int m_windowWidth;
	int m_windowHeight;
	float *m_cameraX;
	float *m_cameraY;
	//SDL_Event *m_event;
	bool m_onePress;
	int m_mode;
public:
	enum m_modeType {
		game,
		creationMode

	};
	void saveToFile();
	void loadFromFile();
	Environment(SDL_Setup *sdlSetup, int windowWidth,
			int windowHeight, float *cameraX, float *cameraY);
	void backDraw();
	void frontDraw();
	std::vector<Tree*> getTrees();
	void update();

	virtual ~Environment();
};

#endif /* ENVIRONMENT_H_ */
