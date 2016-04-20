/*
 * Tree.cpp
 *
 *  Created on: 9 mar 2016
 *      Author: Michau
 */

#include "Tree.h"

Tree::Tree(SDL_Setup *sdlSetup, int x, int y, float *camerX, float *camerY) {

	m_sdlSetup = sdlSetup;
	m_x = x;
	m_y = y;
	m_cameraX = camerX;
	m_cameraY = camerY;

	m_trunk = new Sprite(m_sdlSetup->getRenderer(), "Assets/trunk.png", m_x,
			m_y, 30, 160, m_cameraX, m_cameraY, CollisionRectangle(4, 130, 20, 20));

	m_crown = new Sprite(m_sdlSetup->getRenderer(), "Assets/crown.png",
			m_x - 50, m_y - 80, 144, 138, m_cameraX, m_cameraY, CollisionRectangle(0, 0, 144, 138));
}

void Tree::drawTrunk() {

	if (170 > *m_cameraY + m_trunk->getRect().y)
	m_trunk->draw();
}
void Tree::drawCrown() {
	if (170 <= *m_cameraY + m_trunk->getRect().y)
		m_trunk->draw();
	m_crown->draw();
}

int Tree::getX() {
	return m_x;
}
int Tree::getY() {
	return m_y;
}

Sprite *Tree::getTrunk() {
	return m_trunk;
}
Sprite *Tree::getCrown() {
	return m_crown;
}

Tree::~Tree() {
	delete m_trunk;
	delete m_crown;
}

