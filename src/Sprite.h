/*
 * Sprite.h
 *
 *  Created on: 3 lut 2016
 *      Author: Michau
 */

#ifndef SPRITE_H_
#define SPRITE_H_
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "CollisionRectangle.h"

class Sprite {

private:
	SDL_Renderer *m_renderer;

	SDL_Texture *m_image;
	SDL_Texture *m_cImage;
	SDL_Rect m_rect;
	SDL_Rect m_crop;
	SDL_Rect m_camera;
	SDL_Rect m_colRect;
	CollisionRectangle m_collision;

	float m_posX;
	float m_posY;
	float m_startX;
	float m_startY;

	int m_frameX;
	int m_frameY;

	int m_frame;
	Uint32 m_timeCheck;

	float *m_cameraX;
	float *m_cameraY;

	int m_imageHeight;
	int m_imageWidth;

public:

	void setX(float x);
	void setY(float y);
	float getX();
	float getY();

	void setStartPos(float startX, float startY);
	void setPos(float x, float y);

	void setupAnimation(int frameX, int frameY);
	void animation(int startFrame, int endFrame, int row, float speed);
	void draw();
	void drawSteady();
	bool isCollaiding(CollisionRectangle collider);
	CollisionRectangle GetCollision();
	SDL_Rect getRect();
	Sprite(SDL_Renderer *renderer, const char *name, int x, int y, int h,
			int w, float *camerX, float *cameraY,  CollisionRectangle collisionRectangle);
	virtual ~Sprite();
};

#endif /* SPRITE_H_ */
