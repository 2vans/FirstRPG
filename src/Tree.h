/*
 * Tree.h
 *
 *  Created on: 9 mar 2016
 *      Author: Michau
 */

#ifndef TREE_H_
#define TREE_H_
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "SDLSetup.h"

class Tree {
private:

	Sprite *m_trunk;
	Sprite *m_crown;
	SDL_Setup *m_sdlSetup;
	float *m_cameraX;
	float *m_cameraY;
	int m_x;
	int m_y;
public:
	int getX();
	int getY();
	Sprite *getTrunk();
	Sprite *getCrown();
	Tree(SDL_Setup *sdlSetup, int x, int y, float *camerX, float *camerY);
	void drawTrunk();
	void drawCrown();
	virtual ~Tree();
};

#endif /* TREE_H_ */
