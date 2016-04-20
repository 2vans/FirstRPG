/*
 * Inventory.cpp
 *
 *  Created on: 6 kwi 2016
 *      Author: Michau
 */

#include "Inventory.h"

Inventory::Inventory(SDL_Setup *sdlSetup, float *cameraX, float *cameraY, int x,
		int y) {

	m_sdlSetup = sdlSetup;
	m_cameraX = cameraX;
	m_cameraY = cameraY;
	m_x = x;
	m_y = y;

	m_mainBlock = new Sprite(sdlSetup, "Assets/inv.bmp", m_x,
			m_y, 30, 160, m_cameraX, m_cameraY, CollisionRectangle());

}

void Inventory::drawInv() {
	m_mainBlock.draw();
}

Inventory::~Inventory() {
	// TODO Auto-generated destructor stub
}

