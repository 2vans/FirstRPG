/*
 * Inventory.h
 *
 *  Created on: 6 kwi 2016
 *      Author: Michau
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "SDLSetup.h"
#include "CollisionRectangle.h"

class Inventory {
private:
	Sprite m_mainBlock;
	SDL_Setup *m_sdlSetup;
	float *m_cameraX;
	float *m_cameraY;
	int m_x;
	int m_y;
public:
	Inventory(SDL_Setup *sdlSetup, float *cameraX, float *cameraY,
			int x, int y);
	virtual ~Inventory();
	void drawInv();
};

#endif /* INVENTORY_H_ */
