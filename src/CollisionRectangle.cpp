/*
 * CollisionRectangle.cpp
 *
 *  Created on: 17 mar 2016
 *      Author: Michau
 */

#include "CollisionRectangle.h"

CollisionRectangle::CollisionRectangle() {
	m_x = 0;
	m_y = 0;
	setRect(0, 0, 0, 0);

}

CollisionRectangle::CollisionRectangle(int x, int y, int w, int h) {
	m_x = x;
	m_y = y;
	setRect(0, 0, w, h);
}

void CollisionRectangle::setRect(int x, int y, int w, int h) {
	m_rect.x = x + m_x;
	m_rect.y = y + m_y;
	m_rect.h = h;
	m_rect.w = w;
}

void  CollisionRectangle::setX(int x) {
	m_rect.x = x + m_x;
}

void  CollisionRectangle::setY(int y){
	m_rect.y = y + m_y;
}

SDL_Rect CollisionRectangle::getCollisionRect() {
	return m_rect;
}

CollisionRectangle::~CollisionRectangle() {
	// TODO Auto-generated destructor stub
}

