/*
 * CollisionRectangle.h
 *
 *  Created on: 17 mar 2016
 *      Author: Michau
 */

#ifndef COLLISIONRECTANGLE_H_
#define COLLISIONRECTANGLE_H_
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

class CollisionRectangle {
private:
	int m_x;
	int m_y;
	SDL_Rect m_rect;
public:
	void setX(int x);
	void setY(int y);
	CollisionRectangle();
	CollisionRectangle(int x, int y, int w, int h);
	void setRect(int x, int y, int w, int h);
	SDL_Rect getCollisionRect();
	virtual ~CollisionRectangle();

};

#endif /* COLLISIONRECTANGLE_H_ */
